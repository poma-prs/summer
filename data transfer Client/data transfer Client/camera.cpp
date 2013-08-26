
#include <windows.h>
#include "camera.h"
#include "math.h"

void CCamera::SetViewByMouse()
{
	POINT mousePos;

	int middleX = GetSystemMetrics(SM_CXSCREEN) >> 1;
	int middleY = GetSystemMetrics(SM_CYSCREEN) >> 1;
	float rotY = 0.0f;
	float rotX = 0.0f;

	GetCursorPos(&mousePos);

	if( (mousePos.x == middleX) && (mousePos.y == middleY) ) return;

	SetCursorPos(middleX, middleY);

	rotY = (float)((middleX - mousePos.x)) / 1000.0f;
	rotX = (float)((middleY - mousePos.y)) / 1000.0f;

	if(curRotX + rotX > 1.0f)
	{ 
		if(curRotX != 1.0f)
		{
			CVector3 vAxis = CrossProduct(m_vView - m_vPosition, m_vUpVector);
			vAxis = Normalize(vAxis);

			curRotX = 1.0f;
			RotateAroundPoint(m_vView, 1.0f - curRotX, vAxis.x, vAxis.y, vAxis.z);
		}
	}
	else if(curRotX + rotX < -1.0f)
	{
		if(curRotX != -1.0f)
		{
			CVector3 vAxis = CrossProduct(m_vView - m_vPosition, m_vUpVector);
			vAxis = Normalize(vAxis);

			curRotX = -1.0f;
			RotateAroundPoint(m_vView, -1.0f - curRotX, vAxis.x, vAxis.y, vAxis.z);
		}
	}
	else
	{
		CVector3 vAxis = CrossProduct(m_vView - m_vPosition, m_vUpVector);
		vAxis = Normalize(vAxis);

		curRotX += rotX;
		RotateAroundPoint(m_vView, rotX, vAxis.x, vAxis.y, vAxis.z);
	}

	RotateAroundPoint(m_vView, rotY, 0.0f, 1.0f, 0.0f);
}

void CCamera::RotateView(float angle, float x, float y, float z)
{
	CVector3 vNewView;
	CVector3 vView;

	vView.x = m_vView.x - m_vPosition.x;
	vView.y = m_vView.y - m_vPosition.y;
	vView.z = m_vView.z - m_vPosition.z;

	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	vNewView.x  = (cosTheta + (1 - cosTheta) * x * x)		* vView.x;
	vNewView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vView.y;
	vNewView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vView.z;

	vNewView.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* vView.x;
	vNewView.y += (cosTheta + (1 - cosTheta) * y * y)		* vView.y;
	vNewView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vView.z;

	vNewView.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* vView.x;
	vNewView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vView.y;
	vNewView.z += (cosTheta + (1 - cosTheta) * z * z)		* vView.z;

	m_vView.x = m_vPosition.x + vNewView.x;
	m_vView.y = m_vPosition.y + vNewView.y;
	m_vView.z = m_vPosition.z + vNewView.z;
}

void CCamera::RotateAroundPoint(CVector3 vCenter, float angle, float x, float y, float z)
{
	if (x == 0.0f && y == 1.0f && z == 0.0f)
	{
		curRotY += angle;
		while (curRotY > Pi) curRotY -= 2 * Pi;
		while (curRotY <= -Pi) curRotY += 2 * Pi;
	}

	CVector3 vNewPosition;

	CVector3 vPos = m_vPosition - vCenter;

	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);

	vNewPosition.x  = (cosTheta + (1 - cosTheta) * x * x)		* vPos.x;
	vNewPosition.x += ((1 - cosTheta) * x * y - z * sinTheta)	* vPos.y;
	vNewPosition.x += ((1 - cosTheta) * x * z + y * sinTheta)	* vPos.z;

	vNewPosition.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* vPos.x;
	vNewPosition.y += (cosTheta + (1 - cosTheta) * y * y)		* vPos.y;
	vNewPosition.y += ((1 - cosTheta) * y * z - x * sinTheta)	* vPos.z;

	vNewPosition.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* vPos.x;
	vNewPosition.z += ((1 - cosTheta) * y * z + x * sinTheta)	* vPos.y;
	vNewPosition.z += (cosTheta + (1 - cosTheta) * z * z)		* vPos.z;

	m_vPosition = vCenter + vNewPosition;
}

void CCamera::MoveCameraForward(float speed)
{
	CVector3 vVector = m_vView - m_vPosition;
	vVector.Normalize();

	m_vPosition.x += vVector.x * speed;
	m_vPosition.z += vVector.z * speed;
	m_vView.x += vVector.x * speed;
	m_vView.z += vVector.z * speed;
}

void CCamera::MoveCameraSide(float speed)
{
	CVector3 vVector = m_vView - m_vPosition;
	vVector.Normalize();
	vVector = vVector.Cross(m_vUpVector);

	m_vPosition.x += vVector.x * speed;
	m_vPosition.z += vVector.z * speed;
	m_vView.x += vVector.x * speed;
	m_vView.z += vVector.z * speed;
}