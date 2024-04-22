#include "Vertex.h"

#include <iostream>
#include <cmath>

CVertex::CVertex(float v1, float v2, float v3)
	:m_v11(v1),m_v12(v2),m_v13(v3)
{
	
}
CVertex::CVertex(const CVertex& other)
	:m_v11(other.m_v11),m_v12(other.m_v12),m_v13(other.m_v13)
{

}
CVertex& CVertex::CVertex::operator=(const CVertex& other)
{
	if (*this == other)
		return *this;

	m_v11 = other.m_v11;
	m_v12 = other.m_v12;
	m_v13 = other.m_v13;

	return *this;
}

bool CVertex::operator==(const CVertex& other)
{
	return m_v11 == other.m_v11 &&
		m_v12 == other.m_v12 &&
		m_v13 == other.m_v13;
}

void CVertex::Show() const
{
	auto ToZero = [](float fValue)->float {
		return (abs(fValue) < 1e-6) ? 0 : fValue;
	};

	std::cout << ToZero(m_v11)
		<< " " << ToZero(m_v12)
		<< " " << ToZero(m_v13);
}

CVertex operator*(const CVertex& vertex, float fValue)
{
	return CVertex(vertex.m_v11 * fValue, vertex. m_v12 * fValue, vertex.m_v13*fValue);
}
CVertex operator*(float fValue, const CVertex& vertex)
{
	return CVertex(vertex.m_v11 * fValue, vertex.m_v12 * fValue, vertex.m_v13*fValue);
}