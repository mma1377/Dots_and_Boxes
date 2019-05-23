#include "Main_Menu.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	Dots_and_Boxes::Main_Menu main_menu;
	main_menu.ShowDialog();

	return 0;
}

Dots_and_Boxes::Main_Menu::Main_Menu(void)
{
	is_player_red = false;

	InitializeComponent();

}

Dots_and_Boxes::Main_Menu::~Main_Menu()
{
	if (components)
	{
		delete components;
	}
}

System::Void Dots_and_Boxes::Main_Menu::start_game_btn_Click(System::Object ^ sender, System::EventArgs ^ e)
{

	bool player_start_first;

	if (player_start_first_radio->Checked == true)
		player_start_first = true;
	else {
		player_start_first = false;
	}

	Dots_and_Boxes::Game_Table game_table(game_size_track_bar->Value, player_start_first, is_player_red);

	this->Hide();
	game_table.ShowDialog();
}

System::Void Dots_and_Boxes::Main_Menu::change_color_btn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (is_player_red) {
		player_start_first_radio->ForeColor = System::Drawing::Color::Blue;
		bot_start_first_radio->ForeColor = System::Drawing::Color::Red;
		is_player_red = false;
	}
	else {
		player_start_first_radio->ForeColor = System::Drawing::Color::Red;
		bot_start_first_radio->ForeColor = System::Drawing::Color::Blue;
		is_player_red = true;
	}
}
