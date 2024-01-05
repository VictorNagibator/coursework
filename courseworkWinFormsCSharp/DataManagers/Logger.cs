using System;
using System.IO;

namespace courseworkWinFormsCSharp.DataManagers
{
    internal class Logger
    {
        internal static void Log(int idOfOrder, OrderOperation operation)
        {
            string filePath = "..\\log.txt";
            try
            {
                using (StreamWriter file = new StreamWriter(filePath, true))
                {
                    DateTime currentTime = DateTime.Now;
                    file.WriteLine($"Файл {FileInfo.Path}; Заказ {idOfOrder} был {operation}; {currentTime}");
                }
            }
            catch (Exception ex)
            {
                throw new ArgumentException($"Ошибка при записи в файл: {ex.Message}");
            }
        }
    }
}
