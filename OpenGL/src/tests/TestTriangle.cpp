#include "TestTriangle.h"

namespace test
{
	TestTriangle::TestTriangle()
		: m_Positions {
			 0.0f,  0.5f,
			-0.5f, -0.5f,
			 0.5f, -0.5f,
						},
		m_Indices {0,1,2},
		m_IB(m_Indices, 3),
		m_Shader("res/shaders/Color.shader")
	{
		VertexBuffer vb(m_Positions, 3 * 2 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		m_VA.AddBuffer(vb, layout);

		m_Shader.Bind();

		m_VA.Unbind();
		vb.Unbind();
		m_IB.Unbind();
		m_Shader.Unbind();		
	}
	TestTriangle::~TestTriangle()
	{
	}
	void TestTriangle::OnUpdate(float deltaTime)
	{
	}
	void TestTriangle::OnRender()
	{		
		m_Renderer.Clear();
		
		m_Renderer.Draw(m_VA, m_IB, m_Shader);
	}
	void TestTriangle::OnImGuiRender()
	{
	}
}