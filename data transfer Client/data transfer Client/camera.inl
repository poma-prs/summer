
#ifndef CAMERA_INL
#define CAMERA_INL

#include "vector.h"

inline CCamera::CCamera()
{
	CVector3 vZero = CVector3(0.0, 0.0, 0.0);
	CVector3 vView = CVector3(0.0, 1.0, 0.5);
	CVector3 vUp = CVector3(0.0, 0.0, 1.0);
 
	m_vPosition = vZero;
	m_vView = vView;
	m_vUpVector = vUp;
}

inline void CCamera::PositionCamera(float positionX, float positionY, float positionZ,
		float viewX, float viewY, float viewZ, 
		float upVectorX, float upVectorY, float upVectorZ)
{
	CVector3 vPosition	= CVector3(positionX, positionY, positionZ);
	CVector3 vView		= CVector3(viewX, viewY, viewZ);
	CVector3 vUpVector	=  CVector3(upVectorX, upVectorY, upVectorZ);
 
	m_vPosition = vPosition;
	m_vView = vView;
	m_vUpVector = vUpVector;
}

#endif // CAMERA_INL