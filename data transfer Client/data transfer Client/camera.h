
#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"

class CCamera 
{
	friend class CVector3;

public:
 
	CVector3 m_vPosition;
	CVector3 m_vView;
	CVector3 m_vUpVector;

	CCamera();
 
	void PositionCamera(float positionX, float positionY, float positionZ,
	        			float viewX,     float viewY,     float viewZ,
						float upVectorX, float upVectorY, float upVectorZ);
	void MoveCameraForward(float speed);
	void MoveCameraSide(float speed);
	void RotateView(float angle, float x, float y, float z);
	void SetViewByMouse();
	void RotateAroundPoint(CVector3 vCenter, float angle, float x, float y, float z);

	float curRotX, curRotY;
};

extern CCamera	g_Camera;

#include "camera.inl"

#endif // CAMERA_H