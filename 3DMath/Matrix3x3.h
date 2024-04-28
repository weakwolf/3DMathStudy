#ifndef __MATRIX3X3__
#define __MATRIX3X3__

#include "Vertex.h"

// ��ת����������������
enum ERotateType
{
	ERT_Invalid = 0,
	ERT_X,		// X��
	ERT_Y,		// Y��
	ERT_Z,		// Z��
	ERT_Count
};

// �����ඨ��
// 3x3
class CMatrix3x3
{
public:
	// bigthree
	CMatrix3x3(float v11 = 1.0f, float v12 = 0.0f, float v13 = 0.0f,
		float v21 = 0.0f, float v22 = 1.0f, float v23 = 0.0f,
		float v31 = 0.0f, float v32 = 0.0f, float v33 = 1.0f);
	CMatrix3x3(const CVertex& v1, const CVertex& v2, const CVertex& v3);
	CMatrix3x3(const CMatrix3x3& other);
	CMatrix3x3& operator=(const CMatrix3x3& other);
	bool operator==(const CMatrix3x3& other);

public:
	void Show() const;

public:
	// ���þ���Ϊ��ת����--��X�ᣬY�ᣬZ��
	void SetRotate(ERotateType type, float fAngle);
	// ����Ϊ��λ����
	void SetIdentityMatrix();

public:
	// ʹ��������������ʾ
	CVertex m_vertex1;
	CVertex m_vertex2;
	CVertex m_vertex3;
};

CMatrix3x3 operator*(const CMatrix3x3& left, const CMatrix3x3& right);
CVertex operator*(const CVertex& vertex, const CMatrix3x3& matrix);

#endif
