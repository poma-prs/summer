
#ifndef VECTOR_INL
#define VECTOR_INL

//-------------------------------------------------------------
//                        INCLUES                             -
//-------------------------------------------------------------
#include <cmath>
#include "matrix.h"

//-------------------------------------------------------------
//                       CVector2                             -
//-------------------------------------------------------------
//-------------------------------------------------------------
//-                      FUNCTIONS                            -
//-------------------------------------------------------------
//-------------------------------------------------------------
//- Magnitude
//- Returns the magnitude of the vector
//-------------------------------------------------------------
inline float CVector2::Magnitude() const
{
	return (sqrtf( (x * x) + (y * y) ));
}

//-------------------------------------------------------------
//- Normalize
//- Scales the vector so it has a magnitude of one
//-------------------------------------------------------------
inline void CVector2::Normalize()
{
	float fInvMag = Magnitude();
	if (fInvMag == 0.0f) return;
	fInvMag = 1/fInvMag;
	x *= fInvMag;
	y *= fInvMag;
}

//-------------------------------------------------------------
//- Negate
//- Negates all vector components, equivalent to v *= -1
//-------------------------------------------------------------
inline void CVector2::Negate()
{
	x = -x;
	y = -y;
}

//-------------------------------------------------------------
//- Dot
//- Calculate the dot product of a vector and the stored vector
//-------------------------------------------------------------
inline float CVector2::Dot(const CVector2& vec) const
{
	return( (vec.x * x) + (vec.y * y) );
}


//-------------------------------------------------------------
//-                   OPERATORS                               -
//-------------------------------------------------------------
//-------------------------------------------------------------
//- operator+
//- Add vectors together (vectorC = vectorA + vectorB
//-------------------------------------------------------------
inline const CVector2 CVector2::operator +(const CVector2& vec) const
{
	return( CVector2( ( vec.x + x ), ( vec.y + y )));
}

//-------------------------------------------------------------
//- operator -
//- Subtracts two vectors (vectorC = vectorA - vectorB)
//-------------------------------------------------------------
inline const CVector2 CVector2::operator -(const CVector2& vec) const
{
	return( CVector2( ( x - vec.x ), ( y - vec.y )));
}

//-------------------------------------------------------------
//- operator += 
//- Add a vector to the stored vector
//-------------------------------------------------------------
inline const void CVector2::operator += (const CVector2& vec)
{
	x += vec.x;
	y += vec.y;
}

//-------------------------------------------------------------
//- operator -=
//- Subtract a vector from the stored vector
//-------------------------------------------------------------
inline const void CVector2::operator -= (const CVector2& vec)
{
	x -= vec.x;
	y -= vec.y;
}

//-------------------------------------------------------------
//- operator -
//- Negate the stored vector
//-------------------------------------------------------------
inline const CVector2 CVector2::operator -()
{
	return( CVector2(-x, -y) );
}

//-------------------------------------------------------------
//- operator *
//- Multiply a vector by a scalar
//-------------------------------------------------------------
inline const CVector2 CVector2::operator *(const float fScalar) const
{
	return( CVector2( ( x * fScalar ), ( y * fScalar )));
}

//-------------------------------------------------------------
//- operator /
//- Divide a vector by a scalar
//-------------------------------------------------------------
inline const CVector2 CVector2::operator /(const float fScalar) const
{
	float fInvScale = 1/fScalar;

	return( CVector2( ( x * fInvScale ), ( y * fInvScale )));
}

//-------------------------------------------------------------
//- operator *=
//- Multiply the stored vector by a scalar
//-------------------------------------------------------------
inline const void CVector2::operator *=(const float fScalar)
{
	x *= fScalar;
	y *= fScalar;
}

//-------------------------------------------------------------
//- operator *=
//- Divide the stored vector by a scalar
//-------------------------------------------------------------
inline const void CVector2::operator /=(const float fScalar)
{
	float fInvScale = 1/fScalar;

	x *= fInvScale;
	y *= fInvScale;
}

//-------------------------------------------------------------
//- operator =
//- Set the stored vector equal to another
//-------------------------------------------------------------
inline const void CVector2::operator =(const CVector2& vec)
{
	x = vec.x;
	y = vec.y;
}

//-------------------------------------------------------------
//- operator ==
//- Determines if a vector is equal to another
//-------------------------------------------------------------
inline const bool CVector2::operator ==(const CVector2& vec) const
{
	return ( 
		(x == vec.x) &&
		(y == vec.y));
}

//-------------------------------------------------------------
//- operator !=
//- Determines if two vectors are NOT equal to each other
//-------------------------------------------------------------
inline const bool CVector2::operator !=(const CVector2& vec) const
{
	return (!(*this == vec));
}

//-------------------------------------------------------------
//- Constuctors
//- 1. Default Constructor (no parameters, initializes to 0)
//- 2. Copy Constructor (takes another CVector2 and copies it)
//- 3. 2 floats (takes 2 floats one for X and one for Y components)
//- 4. float array (takes a pointer to an array of floats and uses
//     the first and second element for the X and Y components)
//-------------------------------------------------------------
inline CVector2::CVector2()
{
	x = 0;
	y = 0;
}

inline CVector2::CVector2(const CVector2& vec)
{
	x = vec.x;
	y = vec.y;
}

inline CVector2::CVector2(float fX, float fY)
{
	x = fX;
	y = fY;
}

inline CVector2::CVector2(float * vec)
{
	x = vec[0];
	y = vec[1];
}

//-------------------------------------------------------------
//- Accessors
//- 1. Get (returns a pointer to the array)
//- 2. Set (takes 2 floats, one for each component)
//- 3. Set (takes a pointer to a float array, the first two 
//     elements are used)
//-------------------------------------------------------------
inline float * CVector2::Get()
{
	float * m_fVec;
	m_fVec[0] = x;
	m_fVec[1] = y;

	return m_fVec;
}

inline void CVector2::Set(float fX, float fY)
{
	x = fX;
	y = fY;
}

inline void CVector2::Set(float * vec)
{
	x = vec[0];
	y = vec[1];
}

//-------------------------------------------------------------
//                     END CVector2                           -
//-------------------------------------------------------------


//-------------------------------------------------------------
//                       CVector3                             -
//-------------------------------------------------------------
//-------------------------------------------------------------
//-                      FUNCTIONS                            -
//-------------------------------------------------------------
//-------------------------------------------------------------
//- Magnitude
//- Returns the magnitude of the vector
//-------------------------------------------------------------
inline float CVector3::Magnitude() const
{
	return (sqrtf( (x * x) + (y * y) + (z * z)));
}

//-------------------------------------------------------------
//- Normalize
//- Scales the vector so it has a magnitude of one
//-------------------------------------------------------------
inline void CVector3::Normalize()
{
	float fInvMag = Magnitude();
	if (fInvMag == 0.0f) return;
	fInvMag = 1 / fInvMag;
	x *= fInvMag;
	y *= fInvMag;
	z *= fInvMag;
}

//-------------------------------------------------------------
//- Negate
//- Negates all vector components, equivalent to v *= -1
//-------------------------------------------------------------
inline void CVector3::Negate()
{
	x = -x;
	y = -y;
	z = -z;
}

//-------------------------------------------------------------
//- Dot
//- Calculate the dot product of a vector and the stored vector
//-------------------------------------------------------------
inline float CVector3::Dot(const CVector3& vec) const
{
	return( (vec.x * x) + (vec.y * y) + (vec.z * z) );
}

//-------------------------------------------------------------
//- Cross
//- Calculates the cross product of a vector and the stored vector
//-------------------------------------------------------------
inline CVector3 CVector3::Cross(const CVector3& vec) const
{
		return ( CVector3( (y * vec.z - z * vec.y), (z * vec.x - x * vec.z), (x * vec.y - y * vec.x)));
}

//-------------------------------------------------------------
//- Transform3
//- Transforms the stored vector by a matrix, either 3x3 or 4x4
//- but uses only the 3x3 matrix if it is a 4x4
//-------------------------------------------------------------
inline void CVector3::Transform3(const CMatrix3X3& mat)
{
	CVector3 temp (
		(x * mat.m_fMat[0] + 
	     y * mat.m_fMat[3] + 
	     z * mat.m_fMat[6]),
	
	    (x * mat.m_fMat[1] +
	     y * mat.m_fMat[4] + 
         z * mat.m_fMat[7]),
	
	    (x * mat.m_fMat[2] +
	     y * mat.m_fMat[5] +
	     z * mat.m_fMat[8]));
	
	*this = temp;
}

inline void CVector3::Transform3(const CMatrix4X4& mat)
{
	CVector3 temp( 
		(x * mat.m_fMat[0] + 
	    y * mat.m_fMat[4] +
	    z * mat.m_fMat[8]),

		(x * mat.m_fMat[1] + 
	    y * mat.m_fMat[5] + 
	    z * mat.m_fMat[9]),

	    (x * mat.m_fMat[2] + 
	    y * mat.m_fMat[6] + 
	    z * mat.m_fMat[10]) );

	*this = temp;
}

//-------------------------------------------------------------
//- Transform4
//- Transforms the stored vector by a 4x4 matrix
//-------------------------------------------------------------
inline void CVector3::Transform4(const CMatrix4X4& mat)
{
	CVector3 temp( 
		(x * mat.m_fMat[0] + 
	    y * mat.m_fMat[4] +
	    z * mat.m_fMat[8] + 
	    mat.m_fMat[12] ),

		(x * mat.m_fMat[1] + 
	    y * mat.m_fMat[5] + 
	    z * mat.m_fMat[9] + 
	    mat.m_fMat[13] ),

	    (x * mat.m_fMat[2] + 
	    y * mat.m_fMat[6] + 
	    z * mat.m_fMat[10]+
	    mat.m_fMat[14]) );

	*this = temp;
}

//-------------------------------------------------------------
//- TransformQ
//- Transform the vector by a rotation quaternion
//-------------------------------------------------------------
inline void CVector3::TransformQ(const CQuaternion& quat)
{
	CQuaternion qv(x, y, z, 0);
	CQuaternion qF = quat * qv * (~quat);
	*this = qF.GetVector();
}

//-------------------------------------------------------------
//-                   OPERATORS                               -
//-------------------------------------------------------------
//-------------------------------------------------------------
//- operator+
//- Add vectors together (vectorC = vectorA + vectorB
//-------------------------------------------------------------
inline const CVector3 CVector3::operator +(const CVector3& vec) const
{
	return( CVector3( ( vec.x + x ), ( vec.y + y ), ( vec.z + z )));
}

//-------------------------------------------------------------
//- operator -
//- Subtracts two vectors (vectorC = vectorA - vectorB)
//-------------------------------------------------------------
inline const CVector3 CVector3::operator -(const CVector3& vec) const
{
	return( CVector3( ( x - vec.x ), ( y - vec.y ), ( z - vec.z )));
}

//-------------------------------------------------------------
//- operator += 
//- Add a vector to the stored vector
//-------------------------------------------------------------
inline const void CVector3::operator += (const CVector3& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

//-------------------------------------------------------------
//- operator -=
//- Subtract a vector from the stored vector
//-------------------------------------------------------------
inline const void CVector3::operator -= (const CVector3& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

//-------------------------------------------------------------
//- operator -
//- Negate the stored vector
//-------------------------------------------------------------
inline const CVector3 CVector3::operator -()
{
	return( CVector3(-x, -y, -z) );
}

//-------------------------------------------------------------
//- operator *
//- Multiply a vector by a scalar
//-------------------------------------------------------------
inline const CVector3 CVector3::operator *(const float fScalar) const
{
	return( CVector3( ( x * fScalar ), ( y * fScalar ),	( z * fScalar )));
}

//-------------------------------------------------------------
//- operator /
//- Divide a vector by a scalar
//-------------------------------------------------------------
inline const CVector3 CVector3::operator /(const float fScalar) const
{
	float fInvScale = 1/fScalar;

	return( CVector3( ( x * fInvScale ), ( y * fInvScale ), ( z * fInvScale )));
}

//-------------------------------------------------------------
//- operator *=
//- Multiply the stored vector by a scalar
//-------------------------------------------------------------
inline const void CVector3::operator *=(const float fScalar)
{
	x *= fScalar;
	y *= fScalar;
	z *= fScalar;
}

//-------------------------------------------------------------
//- operator *=
//- Divide the stored vector by a scalar
//-------------------------------------------------------------
inline const void CVector3::operator /=(const float fScalar)
{
	float fInvScale = 1/fScalar;

	x *= fInvScale;
	y *= fInvScale;
	z *= fInvScale;
}

//-------------------------------------------------------------
//- operator =
//- Set the stored vector equal to another
//-------------------------------------------------------------
inline const void CVector3::operator =(const CVector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

//-------------------------------------------------------------
//- operator ==
//- Determines if a vector is equal to another
//-------------------------------------------------------------
inline const bool CVector3::operator ==(const CVector3& vec) const
{
	return ( (x == vec.x) && (y == vec.y) && (z == vec.z));
}

//-------------------------------------------------------------
//- operator !=
//- Determines if two vectors are NOT equal to each other
//-------------------------------------------------------------
inline const bool CVector3::operator !=(const CVector3& vec) const
{
	return (!(*this == vec));
}

//-------------------------------------------------------------
//- Constuctors
//- 1. Default Constructor (no parameters, initializes to 0)
//- 2. Copy Constructor (takes another CVector2 and copies it)
//- 3. 3 floats (takes 3 floats one for X one for Y and one for Z components)
//- 4. float array (takes a pointer to an array of floats and uses
//     the first - thired element for the X, Y and Z components)
//-------------------------------------------------------------
inline CVector3::CVector3()
{
	x = 0;
	y = 0;
	z = 0;
}

inline CVector3::CVector3(const CVector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

inline CVector3::CVector3(float fX, float fY, float fZ)
{
	x = fX;
	y = fY;
	z = fZ;
}

inline CVector3::CVector3(float * vec)
{
	x = vec[0];
	y = vec[1];
	z = vec[2];
}

//-------------------------------------------------------------
//- Accessors
//- 1. Get (returns a pointer to the array)
//- 2. Set (takes 3 floats, one for each component)
//- 3. Set (takes a pointer to a float array, the first three 
//     elements are used)
//-------------------------------------------------------------
inline float * CVector3::Get()
{
	float * m_fVec;
	m_fVec[0] = x;
	m_fVec[1] = y;
	m_fVec[2] = z;

	return m_fVec;
}

inline void CVector3::Set(float fX, float fY, float fZ)
{
	x = fX;
	y = fY;
	z = fZ;
}

inline void CVector3::Set(float * vec)
{
	x = vec[0];
	y = vec[1];
	z = vec[2];
}

//-------------------------------------------------------------
//                     END CVector3                           -
//-------------------------------------------------------------

#endif //VECTOR_INL