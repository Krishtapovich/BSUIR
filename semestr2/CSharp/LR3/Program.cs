using System;

namespace LR3
{
    class Program
    {
        static void SetArr(Man[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = new Man();
                Console.Write("Ввдедите имя: ");
                arr[i].Name = Console.ReadLine();
                Console.Write("Введите возраст: ");
                arr[i].Age = CheckInt();
                Console.Write("Введите страну: ");
                arr[i].Country = Console.ReadLine();
            }

            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine((i + 1) + ". " + arr[i]);
            }
        }

        static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
            {
                Console.Write("Некорректные данные, попробуйте еще раз: ");
            }
            return a;
        }

        static void Main()
        {
            Man obja = new Man();
            Man objb = new Man("Вася", 18, "Беларусь");
            Console.WriteLine(obja + "\n");
            Console.WriteLine(objb + "\n");

            Man[] arr = new Man[2];
            SetArr(arr);
            Console.WriteLine();
        }
    }
}
