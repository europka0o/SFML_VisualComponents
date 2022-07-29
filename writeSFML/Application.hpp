#pragma once
#include <SFML\Window\Event.hpp>

namespace Platform
{
	class Application
	{
		public:
			Application() = default;

			/// Запустить приложение 
			bool Start();

			/// Завершить выполнение приложения
			bool Exit();

			/// Запустить выполнение программы (главный цикл)
			void Exec();

			/// Запрет на копирование 
			Application operator =(const Application&) = delete;

		private:
			sf::Event appEvent;
	};
}