#pragma once
#include "Game_Data.h"

namespace Dots_and_Boxes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Game_Table : public System::Windows::Forms::Form
	{
	public:
		Game_Table(int _game_size, bool _is_player_starts_first, bool is_player_red);
		

	protected:
		
		~Game_Table();

	private:
		
		System::ComponentModel::Container ^components;
		int game_size;
		bool is_player_starts_first;
		array<System::Windows::Forms::Button^, 2>^ horizontal_btn;
		array<System::Windows::Forms::Button^, 2>^ vertical_btn;
		array<System::Windows::Forms::Button^, 2>^ boxes_btn;
		array<System::Windows::Forms::Button^, 2>^ dots_btn;
		Game_Data* _game_data;
		System::Drawing::Color player_color;
		System::Drawing::Color bot_color;
		System::Windows::Forms::Label^ player_label;
		System::Windows::Forms::Label^ bot_label;
		System::Windows::Forms::Label^ player_score_label;
		System::Windows::Forms::Label^ bot_score_label;
		int player_score;
		int bot_score;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void);

#pragma endregion

	private: 
		System::Void Btn_Line_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Game_Table_Load(System::Object^  sender, System::EventArgs^  e);
		void Bot_Turn_To_Play();
};
}
