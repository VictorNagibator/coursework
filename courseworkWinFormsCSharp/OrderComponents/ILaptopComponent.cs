using Newtonsoft.Json.Linq;

namespace courseworkWinFormsCSharp.OrderComponents
{
    public interface ILaptopComponent
    {
        string GetComponentName();
        string ToString();
        JObject ToJSON();
        void FromJSON(JObject data);
    }
}
