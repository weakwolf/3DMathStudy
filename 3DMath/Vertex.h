#ifndef __VERTEX__
#define __VERTEX__

#include <vector>

// ������Ķ���
// ������
// 1x3
class CVertex
{
public:
	// big three
	CVertex(float v1 = 1.0f, float v2 = 0.0f, float v3 = 0.0f);
	CVertex(const CVertex& other);
	CVertex& operator=(const CVertex& other);
	bool operator==(const CVertex& other);
public:
	void Show() const;
	
public:
	float m_v11;
	float m_v12;
	float m_v13;
};

inline CVertex operator*(const CVertex& vertex, float fValue);	// �����˷����뵥��������
inline CVertex operator*(float fValue, const CVertex& vertex);

#endif
