#include <iostream>
#include <winsock2.h> 
#include <windows.h>

// network
//
#define ADD_CUBE 1
#define REMOVE_CUBE 2
#define COORD_CUBE 3
#define ACTIVE_CUBE 4

using namespace std;

const u_short PORT = 666;

DWORD WINAPI ServeToClient(LPVOID client_socket);
void printUsers();

int activeUsers = 0;

int main() 
{

	char buff[1024]; 

	cout << "This is Server" << endl;

	if (WSAStartup(0x0202, (WSADATA *)&buff[0])) 
	{
		cerr << "Error in WSAStartup: " << WSAGetLastError() << endl;
		return -1;
	}

	SOCKET ServerSocket;

	if ( (ServerSocket = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR) 
	{
		cerr << "Error in socket: " << WSAGetLastError();
		WSACleanup(); 
		return -1;
	}

	sockaddr_in localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(PORT);
	localAddr.sin_addr.s_addr = 0;

	if (bind(ServerSocket, (sockaddr *)&localAddr, sizeof(localAddr)) == SOCKET_ERROR) 
	{
		cerr << "Error in bind: " << WSAGetLastError() << endl;
		closesocket(ServerSocket); 
		WSACleanup();
		return -1;
	}

	if (listen(ServerSocket, 10)) 
	{
		cerr << "Error in listen: " << WSAGetLastError();
		closesocket(ServerSocket);
		WSACleanup();
		return -1;
	}

	cout << "Waiting to new connections..." << endl;

	SOCKET ClientSocket; 
	sockaddr_in clientAddr;

	int clientAddrSize = sizeof(clientAddr);

	while ((ClientSocket = accept(ServerSocket, (sockaddr *)&clientAddr, &clientAddrSize))) 
	{
		++activeUsers;

		HOSTENT *hostName;
		hostName = gethostbyaddr((char *)&clientAddr.sin_addr.s_addr, 4, AF_INET);

		cout << hostName->h_name << " is connect now!" << endl;

		printUsers();
		DWORD thID;
		CreateThread(NULL, NULL, ServeToClient, &ClientSocket, NULL, &thID);
	}
	return 0;
}


DWORD WINAPI ServeToClient(LPVOID client_socket) 
{
	SOCKET mySock;
	mySock = ((SOCKET *)client_socket)[0];
	char buff[20 * 1024];

	int tryRecv, mode;
	while ((tryRecv = recv(mySock, &buff[0], sizeof(buff), 0)) && tryRecv != SOCKET_ERROR)
	{
		memcpy(&mode, buff, sizeof(mode));

		switch (mode)
		{
		case ADD_CUBE:
			{
				cout << "Action: Add cube\n";
				break;
			}
		case REMOVE_CUBE:
			{
				cout << "Action: Remove cube\n";
				break;
			}
		case COORD_CUBE:
			{
				cout << "Action: New coordinates cube\n";
				break;
			}
		case ACTIVE_CUBE:
			{
				cout << "Action: Active cube\n";
				break;
			}
		default:
			break;
		}
	}

	--activeUsers;
	cout << "-disconnect" << endl;
	printUsers();

	closesocket(mySock);
	return 0;
}

void printUsers() 
{
	if (activeUsers) 
		cout << activeUsers << " users on-line" << endl;
	else 
		cout << "No User on-line" << endl;
}