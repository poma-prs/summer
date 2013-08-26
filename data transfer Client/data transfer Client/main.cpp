#include "header.h"

CCamera g_Camera;

bool keys[256];
int i_ActiveCube = -1;
bool changeActiveCube = false;

vector<CCube*> vCubes;

void EventKeysDown()
{
	if (keys[VK_ESCAPE])
	{
		keys[VK_ESCAPE] = false;
		PostQuitMessage(0);
	}

	if (keys[VK_CONTROL] && keys[VK_RETURN])
	{
		keys[VK_CONTROL] = false;
		keys[VK_RETURN] = false;
	}

	if (keys[VK_TAB] && keys[VK_SHIFT])
	{
		if (vCubes.size() != 0)
		{
			i_ActiveCube --;
			if (i_ActiveCube < 0)
				i_ActiveCube = vCubes.size() - 1;
			changeActiveCube = true;
		}
		keys[VK_TAB] = false;
	}
	else if (keys[VK_TAB])
	{
		if (vCubes.size() != 0)
		{
			i_ActiveCube ++;
			if (i_ActiveCube >= (int)vCubes.size())
				i_ActiveCube = 0;
			changeActiveCube = true;
		}
		keys[VK_TAB] = false;
	}

	if (!changeActiveCube)
	{
		if (keys[VK_SPACE] && keys[VK_SHIFT])
		{
			if (vCubes.size() != 0)
			{
				if (i_ActiveCube == vCubes.size() - 1)
				{
					i_ActiveCube --;
					changeActiveCube = true;
				}
				vCubes.pop_back();
			}
			keys[VK_SPACE] = false;
		}
		else if (keys[VK_SPACE])
		{
			vCubes.push_back(new CCube(g_Camera.m_vPosition, 2.0f));
			i_ActiveCube = vCubes.size() - 1;
			keys[VK_SPACE] = false;
		}

		if (keys[VK_A])
		{
			g_Camera.MoveCameraSide(-MOVEMENT_SPEED);
		}

		if (keys[VK_D])
		{
			g_Camera.MoveCameraSide(MOVEMENT_SPEED);
		}

		if (keys[VK_W])
		{
			g_Camera.MoveCameraForward(MOVEMENT_SPEED);
		}

		if (keys[VK_S])
		{
			g_Camera.MoveCameraForward(-MOVEMENT_SPEED);
		}
	}
}

void Main()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
	glColor3f(1.0f, 1.0f, 1.0f);
	APP->Print(.7f, .9f, "FPS: %4.2f", APP->GetFPS());
	APP->Print(.7f, .8f, "Cubes: %d", vCubes.size());
	APP->Print(.7f, .7f, "Active: %d", i_ActiveCube);
	APP->Print(-1.f, .9f, "Position: %.2lf %.2lf %.2lf", g_Camera.m_vPosition.x, g_Camera.m_vPosition.y, g_Camera.m_vPosition.z);
	APP->Print(-1.f, .8f, "View: %.2lf %.2lf %.2lf", g_Camera.m_vView.x, g_Camera.m_vView.y, g_Camera.m_vView.z);
	APP->Print(-1.f, .7f, "Up: %.2lf %.2lf %.2lf", g_Camera.m_vUpVector.x, g_Camera.m_vUpVector.y, g_Camera.m_vUpVector.z);

	APP->Print(-1.f, .6f, "CameraRot: %.2lf", g_Camera.curRotY);
	if (APP->GetSet()->network)
		APP->Print(-1.f, .5f, "IP: %s", APP->GetSet()->ip_server);
	else
		APP->Print(-1.f, .5f, "IP: no");

	glLoadIdentity();

	EventKeysDown();

	if (i_ActiveCube >= 0 && i_ActiveCube < (int)vCubes.size())
	{
		if (changeActiveCube)
		{
			CVector3 vec = vCubes[i_ActiveCube]->GetCenter() - g_Camera.m_vView;

			float angle = vCubes[i_ActiveCube]->angleRotY - g_Camera.curRotY;
			if (g_Camera.curRotY > 0.0f && vCubes[i_ActiveCube]->angleRotY < 0.0f)
			{
				angle = minAbs(angle, 2.0f * Pi + vCubes[i_ActiveCube]->angleRotY - g_Camera.curRotY);
			}
			else if (g_Camera.curRotY < 0.0f && vCubes[i_ActiveCube]->angleRotY > 0.0f)
			{
				angle = minAbs(angle, -2.0f * Pi + vCubes[i_ActiveCube]->angleRotY - g_Camera.curRotY);
			}

			if (vec.Magnitude() <= 2.0f * MOVEMENT_SPEED)
			{
				if (abs(angle) <= MOVEMENT_ANGLE)
				{
					g_Camera.m_vView = vCubes[i_ActiveCube]->GetCenter();
					g_Camera.RotateAroundPoint(g_Camera.m_vView, angle, 0.0f, 1.0f, 0.0f);
					changeActiveCube = false;
				}
				else
				{
					if (angle > 0)
						g_Camera.RotateAroundPoint(g_Camera.m_vView, MOVEMENT_ANGLE, 0.0f, 1.0f, 0.0f);
					else
						g_Camera.RotateAroundPoint(g_Camera.m_vView, -MOVEMENT_ANGLE, 0.0f, 1.0f, 0.0f);
				}
			}
			else
			{
				float k = vec.Magnitude() / (2.0f * MOVEMENT_SPEED);

				if (k > 0.1f)
					g_Camera.RotateAroundPoint(g_Camera.m_vView, angle / k, 0.0f, 1.0f, 0.0f);

				vec.Normalize();
				vec *= 2.0f * MOVEMENT_SPEED;
				g_Camera.m_vView += vec;
				g_Camera.m_vPosition += vec;
			}
		}
		else
		{
			g_Camera.SetViewByMouse();

			vCubes[i_ActiveCube]->Set(g_Camera.m_vView.x, 0.0f, g_Camera.m_vView.z);
			vCubes[i_ActiveCube]->angleRotY = g_Camera.curRotY;
		}
	}

	gluLookAt(g_Camera.m_vPosition.x, g_Camera.m_vPosition.y, g_Camera.m_vPosition.z,
		g_Camera.m_vView.x,	  g_Camera.m_vView.y,	  g_Camera.m_vView.z,
		g_Camera.m_vUpVector.x, g_Camera.m_vUpVector.y, g_Camera.m_vUpVector.z);

	for (size_t i = 0; i < vCubes.size(); i++)
	{
		vCubes[i]->Render();
	}
}

void Init()
{
	static float LightAmbient [] = { 0.5f, 0.5f, 0.5f, 1.0f }; 
	static float LightDiffuse [] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static float LightPosition [] = { 0, 30, 1000, 1};

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);			
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);			
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);		
	glEnable(GL_LIGHT1);

	g_Camera.PositionCamera(0, 1, 6, 0, 0.5f, 0, 0, 1, 0);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	APP->Init(Main);
	APP->CreateWnd();
	Init();
	APP->CreateFnt("Arial", 16);
	APP->Run();
	APP->Destroy();
	return 0;
}

LRESULT CALLBACK CWindow::WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uiMsg)
	{
	case WM_CREATE:
		{
			SetWindowText(hWnd, "Data Transfer Client");

			RECT rectWnd;
			GetWindowRect(hWnd, &rectWnd);
			SetWindowPos(
				hWnd, 
				NULL, 
				GetSystemMetrics(SM_CXSCREEN) / 2 - rectWnd.right  / 2, 
				GetSystemMetrics(SM_CYSCREEN) / 2 - rectWnd.bottom / 2, 
				0, 
				0, 
				SWP_NOSIZE);
		}
	case WM_SYSCOMMAND:
		{
			switch(wParam)
			{
				//Prevent the screensaver from activating
			case SC_SCREENSAVE:
			case SC_MONITORPOWER:
				return 0;
			}
			break;
		}
	case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
	case WM_SIZE:
		{
			Resize(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}
	case WM_KEYDOWN:
		{
			keys[wParam] = true;
			return 0;
		}
	case WM_KEYUP:
		{
			keys[wParam] = false;
			return 0;
		}
	}
	return (DefWindowProc(hWnd, uiMsg, wParam, lParam));
}