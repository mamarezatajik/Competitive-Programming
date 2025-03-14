#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

class Log
{
public:
    string level, message, timestamp;
    Log(const string &level, const string &message, const string &timestamp)
        : level(level), message(message), timestamp(timestamp) {}
};

class User
{
public:
    string password, role;
    double balance;
    int sessionID;
    string sessionStart;

    User() : balance(0), sessionID(0), sessionStart("") {}
    User(const string &password, const string &role)
        : password(password), role(role), balance(0), sessionID(0), sessionStart("") {}
};

class ATMSimulator
{
    static unordered_map<string, User> users;
    static vector<Log> logs;
    static int currentSessionID;

    static bool isTimestampExpired(const string &start, const string &current)
    {
        tm startTime = {}, currentTime = {};
        istringstream ssStart(start);
        istringstream ssCurrent(current);
        ssStart >> get_time(&startTime, "%Y/%m/%d:%H:%M:%S");
        ssCurrent >> get_time(&currentTime, "%Y/%m/%d:%H:%M:%S");

        auto startTimeEpoch = mktime(&startTime);
        auto currentTimeEpoch = mktime(&currentTime);

        return difftime(currentTimeEpoch, startTimeEpoch) > 600;
    }

    static void addLog(const string &level, const string &message, const string &timestamp)
    {
        logs.emplace_back(level, message, timestamp);
        cout << "[" << level << "] " << message << endl;
    }

public:
    static void registerUser(const string &username, const string &password, const string &role, const string &timestamp)
    {
        if (users.find(username) != users.end())
        {
            addLog("ERROR", "user already registered", timestamp);
        }
        else
        {
            users[username] = User(password, role);
            addLog("INFO", "user registered successfully", timestamp);
        }
    }

    static void login(const string &username, const string &password, const string &timestamp)
    {
        auto it = users.find(username);
        if (it == users.end() || it->second.password != password)
        {
            addLog("ERROR", "invalid credentials", timestamp);
            return;
        }

        User &user = it->second;
        if (user.sessionID != 0)
        {
            if (isTimestampExpired(user.sessionStart, timestamp))
            {
                user.sessionID = currentSessionID++;
                user.sessionStart = timestamp;
                addLog("INFO", "user logged in successfully", timestamp);
            }
            else
            {
                addLog("INFO", "already logged in", timestamp);
            }
        }
        else
        {
            user.sessionID = currentSessionID++;
            user.sessionStart = timestamp;
            addLog("INFO", "user logged in successfully", timestamp);
        }
    }

    static void logout(int sessionID, const string &timestamp)
    {
        for (auto &[username, user] : users)
        {
            if (user.sessionID == sessionID)
            {
                user.sessionID = 0;
                user.sessionStart = "";
                addLog("INFO", "user logged out", timestamp);
                return;
            }
        }
        addLog("ERROR", "session expired or invalid", timestamp);
    }

    static void deposit(int sessionID, double amount, const string &timestamp)
    {
        for (auto &[username, user] : users)
        {
            if (user.sessionID == sessionID)
            {
                if (isTimestampExpired(user.sessionStart, timestamp))
                {
                    addLog("ERROR", "session expired", timestamp);
                    return;
                }
                user.balance += amount;
                addLog("INFO", "amount deposited successfully", timestamp);
                return;
            }
        }
        addLog("ERROR", "session expired or invalid", timestamp);
    }

    static void withdraw(int sessionID, double amount, const string &timestamp)
    {
        for (auto &[username, user] : users)
        {
            if (user.sessionID == sessionID)
            {
                if (isTimestampExpired(user.sessionStart, timestamp))
                {
                    addLog("ERROR", "session expired", timestamp);
                    return;
                }
                if (user.balance < amount)
                {
                    addLog("ERROR", "insufficient funds", timestamp);
                    return;
                }
                user.balance -= amount;
                addLog("INFO", "amount withdrawn successfully", timestamp);
                return;
            }
        }
        addLog("ERROR", "session expired or invalid", timestamp);
    }

    static void transfer(int sessionID, const string &targetUser, double amount, const string &timestamp)
    {
        for (auto &[username, user] : users)
        {
            if (user.sessionID == sessionID)
            {
                if (isTimestampExpired(user.sessionStart, timestamp))
                {
                    addLog("ERROR", "session expired", timestamp);
                    return;
                }
                auto targetIt = users.find(targetUser);
                if (targetIt == users.end())
                {
                    addLog("ERROR", "target user not found", timestamp);
                    return;
                }
                if (user.balance < amount)
                {
                    addLog("ERROR", "insufficient funds", timestamp);
                    return;
                }
                user.balance -= amount;
                targetIt->second.balance += amount;
                addLog("INFO", "amount transferred successfully", timestamp);
                return;
            }
        }
        addLog("ERROR", "session expired or invalid", timestamp);
    }

    static void queryLog(const string &level, const string &t1, const string &t2, const string &timestamp)
    {
        cout << "[DEBUG] get log " << level << endl;
        if (!t1.empty())
            cout << " " << t1 << endl;
        if (!t2.empty())
            cout << " " << t2 << endl;

        bool found = false;
        for (const auto &log : logs)
        {
            if (log.level == level)
            {
                if (!t1.empty() && log.timestamp < t1)
                    continue;
                if (!t2.empty() && log.timestamp > t2)
                    continue;
                cout << log.timestamp << " " << log.level << " " << log.message << endl;
                found = true;
            }
        }
        if (!found)
            cout << "no logs found" << endl;
    }
};

// Static member initialization
unordered_map<string, User> ATMSimulator::users;
vector<Log> ATMSimulator::logs;
int ATMSimulator::currentSessionID = 1;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string command;

        cin >> command;
        if (command == "register")
        {
            string username, password, role, timestamp;
            cin >> username >> password >> role >> timestamp;
            ATMSimulator::registerUser(username, password, role, timestamp);
        }
        else if (command == "login")
        {
            string username, password, timestamp;
            cin >> username >> password >> timestamp;
            ATMSimulator::login(username, password, timestamp);
        }
        else if (command == "logout")
        {
            int sessionID;
            string timestamp;
            cin >> sessionID >> timestamp;
            ATMSimulator::logout(sessionID, timestamp);
        }
        else if (command == "deposit")
        {
            int sessionID;
            double amount;
            string timestamp;
            cin >> sessionID >> amount >> timestamp;
            ATMSimulator::deposit(sessionID, amount, timestamp);
        }
        else if (command == "withdraw")
        {
            int sessionID;
            double amount;
            string timestamp;
            cin >> sessionID >> amount >> timestamp;
            ATMSimulator::withdraw(sessionID, amount, timestamp);
        }
        else if (command == "transfer")
        {
            int sessionID;
            string targetUser, timestamp;
            double amount;
            cin >> sessionID >> targetUser >> amount >> timestamp;
            ATMSimulator::transfer(sessionID, targetUser, amount, timestamp);
        }
        else if (command == "log")
        {
            string level, t1, t2, timestamp;
            cin >> level >> t1 >> t2 >> timestamp;
            ATMSimulator::queryLog(level, t1, t2, timestamp);
        }
    }
    return 0;
}