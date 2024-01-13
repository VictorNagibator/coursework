using System;
using System.Windows.Forms;
using courseworkWinFormsCSharp.DataManagers;

namespace courseworkWinFormsCSharp.Forms
{
    public partial class TableForm : Form
    {
        public TableForm()
        {
            InitializeComponent();

            if (!string.IsNullOrEmpty(FileInfo.Path))
            {
                OrdersData.LoadOrders(FileInfo.Path);

                LoadDataInTable();
                FileInfoLabel.Text = "Рабочий файл: " + FileInfo.Path;
                работаСДаннымиToolStripMenuItem.Enabled = true;

                if (OrdersData.Data.Count == 0)
                {
                    изменитьЗаписьToolStripMenuItem.Enabled = false;
                    удалитьЗаписьToolStripMenuItem.Enabled = false;
                }
            }
            else FileInfoLabel.Text = "Рабочий файл: не выбран";
        }

        private void выйтиВГлавноеМенюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void игратьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this, "К сожалению, Алексей еще не реализовал игру! Также прошу напомнить ему, что он должен забрать кроссовки со спортманежа!", "Игра", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void выбратьФайлToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Filter = "JSON файлы(*.json)|*.json"
            };
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filename = openFileDialog.FileName;
                try
                {
                    FileInfo.Path = filename;
                    работаСДаннымиToolStripMenuItem.Enabled = true;
                    LoadDataInTable();

                    FileInfoLabel.Text = "Рабочий файл: " + FileInfo.Path;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(this, ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void LoadDataInTable()
        {
            dataGridView.Rows.Clear();
            foreach (var order in OrdersData.Data)
            {
                dataGridView.Rows.Add(order.ID, order.Laptop.ModelName, order.Status);
            }
        }

        private void добавитьЗаписьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddDataForm form = new AddDataForm();
            form.ShowDialog();
            LoadDataInTable();

            if (OrdersData.Data.Count != 0)
            {
                изменитьЗаписьToolStripMenuItem.Enabled = true;
                удалитьЗаписьToolStripMenuItem.Enabled = true;
            }
        }

        private void удалитьЗаписьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DeleteDataForm form = new DeleteDataForm();
            form.ShowDialog();
            LoadDataInTable();

            if (OrdersData.Data.Count == 0)
            {
                изменитьЗаписьToolStripMenuItem.Enabled = false;
                удалитьЗаписьToolStripMenuItem.Enabled = false;
            }
        }
    }
}
