using courseworkWinFormsCSharp.Forms;
using System;
using System.Windows.Forms;

namespace courseworkWinFormsCSharp
{
    public partial class MainMenuForm : Form
    {
        public MainMenuForm()
        {
            InitializeComponent();
        }

        private void ExitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void OpenLoggerButton_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("..\\log.txt");
        }

        private void PlayButton_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this, "Какое слово начинается на три Г и заканчивается на три Я?", "Игра", MessageBoxButtons.OK, MessageBoxIcon.Question);
            MessageBox.Show(this, "Тригонометрия!", "Ответ", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void WorkWithDataButton_Click(object sender, EventArgs e)
        {
            TableForm form = new TableForm();
            //Hide();
            form.ShowDialog();
        }
    }
}
