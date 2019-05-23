#include "Game_Table.h"

void Dots_and_Boxes::Game_Table::Bot_Turn_To_Play() {

	this->Enabled = false;

	int ret_result_bot = 1;

	int counter = 0;
	while (ret_result_bot) {
		int bot_x_choose, bot_y_choose;
		bool bot_direction_choose;
		ret_result_bot = _game_data->Start_Abstract_Game(4, bot_direction_choose, bot_x_choose, bot_y_choose);

		if (ret_result_bot == -1) {
			this->Enabled = true;
			bot_score_label->Text = bot_score.ToString();
			return;
		}
		if (bot_direction_choose == false) {
			vertical_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
			vertical_btn[bot_x_choose, bot_y_choose]->Enabled = false;

			if (ret_result_bot == 1) {
				boxes_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose]->FlatAppearance->BorderSize = 1;
				bot_score++;
			}
			else if (ret_result_bot == 2) {
				boxes_btn[bot_x_choose - 1, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose - 1, bot_y_choose]->FlatAppearance->BorderSize = 1;
				bot_score++;
			}
			else if (ret_result_bot == 3) {
				boxes_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose - 1, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose]->FlatAppearance->BorderSize = 1;
				boxes_btn[bot_x_choose - 1, bot_y_choose]->FlatAppearance->BorderSize = 1;
				bot_score += 2;
			}
		}
		else {
			horizontal_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
			horizontal_btn[bot_x_choose, bot_y_choose]->Enabled = false;
			ret_result_bot = _game_data->Select_Line(1, bot_x_choose, bot_y_choose);
			if (ret_result_bot == 1) {
				boxes_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose]->FlatAppearance->BorderSize = 1;
				bot_score++;
			}
			else if (ret_result_bot == 2) {
				boxes_btn[bot_x_choose, bot_y_choose - 1]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose - 1]->FlatAppearance->BorderSize = 1;
				bot_score++;
			}
			else if (ret_result_bot == 3) {
				boxes_btn[bot_x_choose, bot_y_choose]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose - 1]->BackColor = bot_color;
				boxes_btn[bot_x_choose, bot_y_choose]->FlatAppearance->BorderSize = 1;
				boxes_btn[bot_x_choose, bot_y_choose - 1]->FlatAppearance->BorderSize = 1;
				bot_score += 2;
			}
		}
	}

	bot_score_label->Text = bot_score.ToString();

	this->Enabled = true;

}

Dots_and_Boxes::Game_Table::Game_Table(int _game_size, bool _is_player_starts_first, bool is_player_red)
{
	game_size = _game_size;
	is_player_starts_first = _is_player_starts_first;

	if (is_player_red) {
		player_color = System::Drawing::Color::Red;
		bot_color = System::Drawing::Color::Blue;
	}
	else {
		player_color = System::Drawing::Color::Blue;
		bot_color = System::Drawing::Color::Red;
	}


	InitializeComponent();

	_game_data = new Game_Data(game_size);

}

Dots_and_Boxes::Game_Table::~Game_Table()
{
	if (components)
	{
		delete components;
	}
}

void Dots_and_Boxes::Game_Table::InitializeComponent(void)
{
	this->SuspendLayout();
	// 
	// Game_Table
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::White;
	this->ClientSize = System::Drawing::Size(284, 261);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
	this->Name = L"Game_Table";
	this->RightToLeftLayout = true;
	this->Text = L"Dots & Boxes - Algorithm Design Project";
	this->Load += gcnew System::EventHandler(this, &Game_Table::Game_Table_Load);
	this->ResumeLayout(false);

}

System::Void Dots_and_Boxes::Game_Table::Btn_Line_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::Button^ _button = (System::Windows::Forms::Button^)sender;
	String^ _name = _button->Name->ToString();
	array<String^>^ _name_array = _name->Split('-');
	int I = 0;
	int J = 0;
	for (int i = 0; i < _name_array[1]->Length; i++) {
		I *= 10;
		I += _name_array[1][i] - '0';
	}
	for (int i = 0; i < _name_array[2]->Length; i++) {
		J *= 10;
		J += _name_array[2][i] - '0';
	}
	int ret_result = 0;
	if (_name_array[0] == "v") {
		vertical_btn[I, J]->BackColor = player_color;
		vertical_btn[I, J]->Enabled = false;
		ret_result = _game_data->Select_Line(0, I, J);
		//if (ret_result != 0) {
		//	//std::cout << I << "-" << J << "\n";
		//}
		if (ret_result == 1) {
			boxes_btn[I, J]->BackColor = player_color;
			boxes_btn[I, J]->FlatAppearance->BorderSize = 1;
			player_score++;
		}
		else if (ret_result == 2) {
			boxes_btn[I - 1, J]->BackColor = player_color;
			boxes_btn[I - 1, J]->FlatAppearance->BorderSize = 1;
			player_score++;
		}
		else if (ret_result == 3) {
			boxes_btn[I, J]->BackColor = player_color;
			boxes_btn[I - 1, J]->BackColor = player_color;
			boxes_btn[I, J]->FlatAppearance->BorderSize = 1;
			boxes_btn[I - 1, J]->FlatAppearance->BorderSize = 1;
			player_score += 2;
		}
	}
	else if (_name_array[0] == "h") {
		horizontal_btn[I, J]->BackColor = player_color;
		horizontal_btn[I, J]->Enabled = false;
		ret_result = _game_data->Select_Line(1, I, J);
		if (ret_result == 1) {
			boxes_btn[I, J]->BackColor = player_color;
			boxes_btn[I, J]->FlatAppearance->BorderSize = 1;
			player_score++;
		}
		else if (ret_result == 2) {
			boxes_btn[I, J - 1]->BackColor = player_color;
			boxes_btn[I, J - 1]->FlatAppearance->BorderSize = 1;
			player_score++;
		}
		else if (ret_result == 3) {
			boxes_btn[I, J]->BackColor = player_color;
			boxes_btn[I, J - 1]->BackColor = player_color;
			boxes_btn[I, J - 1]->FlatAppearance->BorderSize = 1;
			boxes_btn[I, J - 1]->FlatAppearance->BorderSize = 1;
			player_score += 2;
		}
	}
	player_score_label->Text = player_score.ToString();
	int ret_result_bot = 1;
	if (ret_result == 0)
		Bot_Turn_To_Play();
}

System::Void Dots_and_Boxes::Game_Table::Game_Table_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	this->ClientSize = System::Drawing::Size(48 * game_size + 32 + 60 + 192, 48 * game_size + 48 + 60);
	horizontal_btn = gcnew array<System::Windows::Forms::Button^, 2>(game_size, game_size + 1);
	vertical_btn = gcnew array<System::Windows::Forms::Button^, 2>(game_size + 1, game_size);
	boxes_btn = gcnew array<System::Windows::Forms::Button^, 2>(game_size, game_size);
	dots_btn = gcnew array<System::Windows::Forms::Button^, 2>(game_size + 1, game_size + 1);
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Game_Table::typeid));

	for (int i = 0; i < game_size + 1; i++) {
		for (int j = 0; j < game_size + 1; j++) {
			dots_btn[i, j] = gcnew System::Windows::Forms::Button();
			dots_btn[i, j]->Location = System::Drawing::Point(48 * i + 48, 48 * j + 48);
			dots_btn[i, j]->Size = System::Drawing::Size(10, 10);
			dots_btn[i, j]->BackColor = System::Drawing::Color::Transparent;
			dots_btn[i, j]->BackgroundImage = gcnew Bitmap("dot.png");
			dots_btn[i, j]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			dots_btn[i, j]->FlatAppearance->BorderSize = 0;
			dots_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
			dots_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			dots_btn[i, j]->Enabled = false;
			this->Controls->Add(dots_btn[i, j]);
		}
	}

	for (int i = 0; i < game_size; i++) {
		for (int j = 0; j < game_size + 1; j++) {
			horizontal_btn[i, j] = gcnew System::Windows::Forms::Button();
			horizontal_btn[i, j]->Location = System::Drawing::Point(48 * i + 58, 48 * j + 48);
			horizontal_btn[i, j]->Size = System::Drawing::Size(38, 10);
			horizontal_btn[i, j]->BackColor = System::Drawing::Color::Transparent;
			horizontal_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
			horizontal_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			horizontal_btn[i, j]->FlatAppearance->BorderSize = 0;
			horizontal_btn[i, j]->Name = "h-" + i.ToString() + "-" + j.ToString();
			horizontal_btn[i, j]->Click += gcnew System::EventHandler(this, &Game_Table::Btn_Line_Click);
			horizontal_btn[i, j]->TabStop = false;
			this->Controls->Add(horizontal_btn[i, j]);
		}
	}

	for (int i = 0; i < game_size + 1; i++) {
		for (int j = 0; j < game_size; j++) {
			vertical_btn[i, j] = gcnew System::Windows::Forms::Button();
			vertical_btn[i, j]->Location = System::Drawing::Point(48 * i + 48, 48 * j + 58);
			vertical_btn[i, j]->Size = System::Drawing::Size(10, 38);
			vertical_btn[i, j]->BackColor = System::Drawing::Color::Transparent;
			vertical_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
			vertical_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			vertical_btn[i, j]->FlatAppearance->BorderSize = 0;
			vertical_btn[i, j]->Name = "v-" + i.ToString() + "-" + j.ToString();
			vertical_btn[i, j]->Click += gcnew System::EventHandler(this, &Game_Table::Btn_Line_Click);
			vertical_btn[i, j]->TabStop = false;
			this->Controls->Add(vertical_btn[i, j]);
		}
	}

	for (int i = 0; i < game_size; i++) {
		for (int j = 0; j < game_size; j++) {
			boxes_btn[i, j] = gcnew System::Windows::Forms::Button();
			boxes_btn[i, j]->Location = System::Drawing::Point(48 * i + 58, 48 * j + 58);
			boxes_btn[i, j]->Size = System::Drawing::Size(38, 38);
			boxes_btn[i, j]->BackColor = System::Drawing::Color::Transparent;
			boxes_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
			boxes_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			boxes_btn[i, j]->FlatAppearance->BorderSize = 0;
			boxes_btn[i, j]->Enabled = false;
			this->Controls->Add(boxes_btn[i, j]);
		}
	}

	player_label = gcnew System::Windows::Forms::Label();
	player_label->Location = System::Drawing::Point(48 * game_size + 120 , 45);
	player_label->Text = "Player:";
	player_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(178)));
	player_label->ForeColor = player_color;
	this->Controls->Add(player_label);

	bot_label = gcnew System::Windows::Forms::Label();
	bot_label->Location = System::Drawing::Point(48 * game_size + 120, 95);
	bot_label->Text = "Bot:";
	bot_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(178)));
	bot_label->ForeColor = bot_color;
	this->Controls->Add(bot_label);

	player_score_label = gcnew System::Windows::Forms::Label();
	player_score_label->Location = System::Drawing::Point(48 * game_size + 220, 45);
	player_score_label->Text = "0";
	player_score_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(178)));
	player_score_label->ForeColor = player_color;
	this->Controls->Add(player_score_label);

	bot_score_label = gcnew System::Windows::Forms::Label();
	bot_score_label->Location = System::Drawing::Point(48 * game_size + 220, 95);
	bot_score_label->Text = "0";
	bot_score_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(178)));
	bot_score_label->ForeColor = bot_color;
	this->Controls->Add(bot_score_label);

	player_score = 0;
	bot_score = 0;

	if (!is_player_starts_first)
		Bot_Turn_To_Play();
}
