#pragma once
#include <SFML\Window\Event.hpp>

namespace Platform
{
	class Application
	{
		public:
			Application() = default;

			/// ��������� ���������� 
			bool Start();

			/// ��������� ���������� ����������
			bool Exit();

			/// ��������� ���������� ��������� (������� ����)
			void Exec();

			/// ������ �� ����������� 
			Application operator =(const Application&) = delete;

		private:
			sf::Event appEvent;
	};
}