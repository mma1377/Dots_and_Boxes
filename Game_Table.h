#pragma once

namespace Dots_and_Boxes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game_Table
	/// </summary>
	public ref class Game_Table : public System::Windows::Forms::Form
	{
	public:
		Game_Table(int _game_size)
		{
			game_size = _game_size;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game_Table()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		int game_size;
		array<System::Windows::Forms::Button^, 2>^ horizontal_btn;
		array<System::Windows::Forms::Button^, 2>^ vertical_btn;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
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
			this->Text = L"Game_Table";
			this->Load += gcnew System::EventHandler(this, &Game_Table::Game_Table_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Game_Table_Load(System::Object^  sender, System::EventArgs^  e) {
		this->ClientSize = System::Drawing::Size(32 * game_size + 32 + 40, 32 * game_size + 32 + 40);
		horizontal_btn = gcnew array<System::Windows::Forms::Button^, 2> (game_size + 1, game_size);
		vertical_btn = gcnew array<System::Windows::Forms::Button^, 2> (game_size + 1, game_size);
		for (int i = 0; i < game_size + 1; i++) {
			for (int j = 0; j < game_size; j++) {
				horizontal_btn[i, j] = gcnew System::Windows::Forms::Button();
				horizontal_btn[i, j]->Location = System::Drawing::Point(32 * j + 40, 32 * i + 32);
				horizontal_btn[i, j]->Size = System::Drawing::Size(24, 8);
				horizontal_btn[i, j]->BackColor = System::Drawing::Color::White;
				horizontal_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
				horizontal_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->Controls->Add(horizontal_btn[i, j]);

				vertical_btn[i, j] = gcnew System::Windows::Forms::Button();
				vertical_btn[i, j]->Location = System::Drawing::Point(32 * i + 32, 32 * j + 40);
				vertical_btn[i, j]->Size = System::Drawing::Size(8, 24);
				vertical_btn[i, j]->BackColor = System::Drawing::Color::White;
				vertical_btn[i, j]->Cursor = System::Windows::Forms::Cursors::Hand;
				vertical_btn[i, j]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->Controls->Add(vertical_btn[i, j]);
			}
		}
	}
	};
}
