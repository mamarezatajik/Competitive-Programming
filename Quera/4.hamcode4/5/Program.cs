using System;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Linq;

public class Table {
    public static int TotalEarn = 0;
    public static List<Order> Waiting = new List<Order>();
    public static Dictionary<int, Table> Tables = new Dictionary<int, Table>();
    public Table(int chares) {
        _chares = chares;
        maxChares = Max(maxChares, chares);
        events = new List<Tuple<DateTime, string>>();
        IsEmpty = true;
    }

    public static int maxChares {get; set;}
    public int _chares {get; set;}
    public List<Tuple<DateTime, string>> events;
    public bool IsEmpty {get; set;}

    public void AddAction(string time, string status) {
        int[] t = time.Split(':').Select(c => int.Parse(c)).ToArray();
        DateTime _time = new DateTime(1, 1, 1, t[0], t[1], t[2]);
        events.Add(Tuple.Create(_time, status));
    }

    public string Status(string time) {
        events.Sort();
        int[] t = time.Split(':').Select(c => int.Parse(c)).ToArray();
        DateTime _time = new DateTime(1, 1, 1, t[0], t[1], t[2]);

        string status = "FREE";
        for (int i = 0; i < events.Count; i++)
            if (events[i].Item1 <= _time)
                status = events[i].Item2;
        return status;
    }

    public void Prepare(string time) {
        int[] t = time.Split(':').Select(c => int.Parse(c)).ToArray();
        DateTime tmpTime = new DateTime(1, 1, 1, t[0] + ((t[1] + 2) / 60), (t[1] + 2) % 60, t[2]);
        this.IsEmpty = true;
        this.AddAction(tmpTime.ToString("HH:mm:ss"), "FREE");

        for (int i = 0; i < Waiting.Count; i++) {
            if (Waiting[i]._neededChares <= _chares) {
                Waiting[i]._table = this;
                TotalEarn += Waiting[i].totalCost;
                Waiting.RemoveAt(i);
            }
        }
    }
}

public class Order {
    public static int TotalOrdersCost = 0;
    public static Dictionary<string, int> Price = new Dictionary<string, int>();
    public static Dictionary<int, Order> Orders = new Dictionary<int, Order>();
    public static int Id = 1;
    public List<Tuple<string, int>> _foods {get; set;}
    public int _neededChares {get; set;}
    public DateTime _time {get; set;}
    public Table _table {get; set;}
    public bool Done {get; set;}
    public int totalCost {get; set;}

    public Order(List<string> foods, int neededChares, string time) {
        _neededChares = neededChares;
        int[] t = time.Split(':').Select(c => int.Parse(c)).ToArray();
        _time = new DateTime(1, 1, 1, t[0], t[1], t[2]);

        totalCost = 0;
        _foods = new List<Tuple<string, int>>();
        for (int i = 0; i < foods.Count; i++) {
            var tmp = foods[i].Split('X');
            string food = tmp[0];
            int count = int.Parse(tmp[1]);
            totalCost += Price[food] * count;
            _foods.Add(Tuple.Create(food, count));
        }
        _table = null;
        Done = false;
        TotalOrdersCost += totalCost;
    }

    public string Status() {
        if (Done)
            return "DONE";
        if (_table == null)
            return "WAITING";
        return "EATING";
    }
}

class Program {
    public static void Main() {
        int n, m, k;
        int[] a = ReadLine().Split().Select(c => int.Parse(c)).ToArray();
        n = a[0]; m = a[1]; k = a[2];


        for (int i = 0; i < m; i++) {
            var _ = ReadLine().Split();
            Order.Price.Add(_[0], int.Parse(_[1]));
        }
        int[] tmp = ReadLine().Split().Select(c => int.Parse(c)).ToArray();
        for (int i = 1; i <= k; i++)
            Table.Tables.Add(i, new Table(tmp[i - 1]));


        for (int i = 0; i < n; i++) {
            string[] command = ReadLine().Split();

            if      (command[0] == "order") {
                List<string> foods = new List<string>();
                for (int j = 1; j < command.Length - 2; j++)
                    foods.Add(command[j]);

                int seat = int.Parse(command[command.Length - 2]);
                string time = command[command.Length - 1];
                if (Table.maxChares < seat) {
                    WriteLine("not enough seat.");
                    continue;
                }

                Order order = new Order(foods, seat, time);
                Order.Orders.Add(Order.Id++, order);

                bool ok = false;
                for (int j = 1; j <= k; j++) {
                    if (Table.Tables[j].IsEmpty && Table.Tables[j]._chares >= seat) {
                        Table.Tables[j].IsEmpty = false;
                        order._table = Table.Tables[j];
                        order._table.AddAction(time, "BUSY");
                        ok = true;
                        WriteLine($"please sit at table number {j}.");
                        break;
                    }
                }
                if (!ok) {
                    WriteLine("please wait for free table.");
                    Table.Waiting.Add(order);
                }
            }
            else if (command[0] == "payment") {
                int id = int.Parse(command[1]);
                string time = command[2];
                Order order = Order.Orders[id];

                if (order._table == null) {
                    WriteLine("pays after eating.");
                    continue;
                }

                order._table.AddAction(time, "PENDING");
                WriteLine($"you should pay {order.totalCost} Toman.");
                order._table.Prepare(time);
            }
            else if (command[0] == "order-status") {
                int id = int.Parse(command[1]);
                string time = command[2];
                WriteLine(Order.Orders[id].Status());
            }
            else if (command[0] == "table-status") {
                int id = int.Parse(command[1]);
                string time = command[2];
                WriteLine(Table.Tables[id].Status(time));
            }
            else {            //   general-status
                WriteLine();
            }
        }

    }
}