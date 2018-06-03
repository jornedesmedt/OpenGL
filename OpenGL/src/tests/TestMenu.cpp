#include "TestMenu.h"
#include "TestClearColor.h"
#include "imgui/imgui.h"

#define CREATE_TEST(test) []() -> Test* {return new test();}

namespace test
{
	TestMenu::TestMenu()
		: m_CurrentTest(NULL), m_Menu(new std::map<std::string, TestCreator>())
	{
		m_Menu->emplace("Clear Color", CREATE_TEST(TestClearColor));
	}

	TestMenu::~TestMenu()
	{
		delete m_CurrentTest;
		delete m_Menu;
	}

	void TestMenu::OnUpdate(float deltaTime)
	{
		if (m_CurrentTest != NULL)
		{
			m_CurrentTest->OnUpdate(deltaTime);
		}
	}

	void TestMenu::OnRender()
	{
		if (m_CurrentTest != NULL)
		{
			m_CurrentTest->OnRender();
		}
	}

	void TestMenu::OnImGuiRender()
	{
		if (m_CurrentTest != NULL)
		{
			m_CurrentTest->OnImGuiRender();
			//Render back button
		}
		else
		{
			//Render menu
		}
	}
}