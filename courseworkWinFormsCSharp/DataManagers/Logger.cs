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
                    file.WriteLine($"File {FileInfo.Path}; Order {idOfOrder} was changed by {operation}; {currentTime}");
                }
            }
            catch (Exception ex)
            {
                throw new ArgumentException($"Ошибка при записи в файл: {ex.Message}");
            }
        }
    }
}
