
#ifndef CUBE_INL
#define CUBE_INL

#include "vector.h"

inline CColorVertexCube::CColorVertexCube()
{
	for (int i = 0; i < 3; i++)
		m_fColor[i] = 0.0f;
}

inline CColorVertexCube::CColorVertexCube(float fR, float fG, float fB)
{
	m_fColor[0] = fR;
	m_fColor[1] = fG;
	m_fColor[2] = fB;
}

inline CColorVertexCube::CColorVertexCube(const CColorVertexCube& colCopy)
{
	m_fColor[0] = colCopy.m_fColor[0];
	m_fColor[1] = colCopy.m_fColor[1];
	m_fColor[2] = colCopy.m_fColor[2];
}

inline float * CColorVertexCube::Get()
{
	return m_fColor;
}

inline float& CColorVertexCube::operator[] (const int iInd)
{
	return m_fColor[iInd];
}






inline CVertexCube::CVertexCube()
{
	for (int i = 0; i < 3; i++)
		m_fVer[i] = 0.0f;
	color = new CColorVertexCube();
}

inline CVertexCube::CVertexCube(float fX, float fY, float fZ)
{
	m_fVer[0] = fX;
	m_fVer[1] = fY;
	m_fVer[2] = fZ;
	color = new CColorVertexCube();
}

inline CVertexCube::CVertexCube(float fX, float fY, float fZ, const CColorVertexCube& col)
{
	m_fVer[0] = fX;
	m_fVer[1] = fY;
	m_fVer[2] = fZ;
	color = new CColorVertexCube(col);
}

inline float& CVertexCube::operator[] (const int iInd)
{
	return m_fVer[iInd];
}







inline void CCube::Set(float fLenCopy)
{
	fLen = fLenCopy;
}

inline void CCube::Set(CVector3& centerCopy)
{
	Center = centerCopy;
}

inline void CCube::Set(float fX, float fY, float fZ)
{
	Center.Set(fX, fY, fZ);
}

inline void CCube::Set(CVector3& centerCopy, float fLenCopy)
{
	Center = centerCopy;
	fLen = fLenCopy;
}

inline void CCube::Set(float fX, float fY, float fZ, float fLenCopy)
{
	Center.Set(fX, fY, fZ);
	fLen = fLenCopy;
}

inline CVector3 CCube::GetCenter()
{
	return Center;
}

inline CCube::CCube()
{
	fLen = 0.0f;
	Center = CVector3();
}

inline CCube::CCube(CVector3& CenterCopy, float fLenCopy)
{
	fLen = fLenCopy / 2.0f;
	Center = CVector3(CenterCopy);
}

inline CCube::CCube(const CCube& cubeCopy)
{
	fLen = cubeCopy.fLen;
	Center = CVector3(cubeCopy.Center);
}

#endif // CUBE_INL