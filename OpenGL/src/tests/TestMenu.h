#pragma once

#include <string>
#include <map>
#include "Test.h"


namespace test
{
	typedef Test *(*TestCreator)(void);
	class TestMenu : public Test
	{
	public:
		TestMenu();
		~TestMenu();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		Test* m_CurrentTest;
		std::map<std::string, TestCreator>* m_Menu;
	};
}