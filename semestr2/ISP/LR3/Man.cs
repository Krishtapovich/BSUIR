using System;

namespace LR3
{
    class Man
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Country { get; set; }
        protected string ID { get; set; }

        public Man()
        {
            Name = "Михаил";
            Age = 17;
            Country = "Беларусь";
            ID = GenID();
        }

        public Man(string n = "", int a = 0, string c = "")
        {
            Name = n;
            Age = a;
            Country = c;
            ID = GenID();
        }

        protected static string GenID() => Guid.NewGuid().ToString();

        public override string ToString() => $"Имя: {Name}\nВозраст: {Age}\nСтрана: {Country}\nID: {ID}";
    }
}
