
#ifndef CUBE_H
#define CUBE_H

#include "vector.h"

class CColorVertexCube
{
public:

	float& operator[] (const int iInd);

	CColorVertexCube();
	CColorVertexCube(float fR, float fG, float fB);
	CColorVertexCube(const CColorVertexCube& colCopy);

	float * Get();

private:

	float m_fColor[3];
};

class CVertexCube
{
public:

	float& operator[] (const int iInd);

	CVertexCube();
	CVertexCube(float fX, float fY, float fZ);
	CVertexCube(float fX, float fY, float fZ, const CColorVertexCube& col);

private:

	float m_fVer[3];
	CColorVertexCube* color;
};

class CCube
{
	friend class CVector3;

public:

	// Render the cube
	void Render();
	
	void Set(float fLenCopy);
	void Set(CVector3& centerCopy);
	void Set(float fX, float fY, float fZ);
	void Set(CVector3& centerCopy, float fLenCopy);
	void Set(float fX, float fY, float fZ, float fLenCopy);
	CVector3 GetCenter();

	CCube();
	CCube(CVector3& CenterCopy, float fLenCopy);
	CCube(const CCube& cubeCopy);

	float angleRotY;

private:

	float fLen;
	CVector3 Center;
};

#include "cube.inl"

#endif // CUBE_H