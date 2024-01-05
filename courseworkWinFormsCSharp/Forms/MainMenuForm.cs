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
            MessageBox.Show(this, "К сожалению, Алексей еще не реализовал игру! Также прошу напомнить ему, что он должен забрать кроссовки со спортманежа!", "Игра", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void WorkWithDataButton_Click(object sender, EventArgs e)
        {
            TableForm form = new TableForm();
            form.ShowDialog();
        }
    }
}
