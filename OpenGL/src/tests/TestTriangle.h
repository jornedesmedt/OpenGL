#pragma once

#include "Test.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

namespace test
{
	class TestTriangle : public Test
	{
	public:
		TestTriangle();
		~TestTriangle();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		float m_Positions[12];
		unsigned int m_Indices[3];
		VertexArray m_VA;
		IndexBuffer m_IB;
		Shader m_Shader;
		Renderer m_Renderer;
	};
}