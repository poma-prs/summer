
#ifndef SETTINGS_H
#define SETTINGS_H

class CSettings
{

public:

	bool network;
	char ip_server[100];

	CSettings();

private:

};

inline CSettings::CSettings()
{
	network = false;
}

#endif // SETTINGS_H