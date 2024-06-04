#include <bits/stdc++.h>

struct Guest {
    int arrive, size, duration, id;
    Guest() : arrive(), size(), duration(), id() {}
    Guest(int a, int s, int d, int i) : arrive(a), size(s), duration(d), id(i) {}
};

struct Table {
    int size, releaseTime;
    Table(int s, int r) : size(s), releaseTime(r) {}
};

// comparator of waiting_time
auto cmp_t = [] (Guest a, Guest b) {
    return a.arrive < b.arrive;
};

// comparator of waiting_size
auto cmp_s = [] (Guest a, Guest b) {
    if (a.size != b.size) return a.size > b.size;
    else return a.arrive < b.arrive;
};

// comparator of release
auto cmp_r = [] (Table a, Table b) {
    return a.releaseTime < b.releaseTime;
};

std::set<Guest, decltype(cmp_t)> waiting_time(cmp_t); // early->last
std::set<Guest, decltype(cmp_s)> waiting_size(cmp_s); // 1. large->small, 2. early->last
std::multiset<Table, decltype(cmp_r)> release_list(cmp_r); // early->last
std::map<int, int> available_table; // unused table <table size, # of table>

Guest guestInput[200005];
int ans[200005];

void Assign(int time);
void Release(int time);

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int arrive, size, duration;
        std::cin >> arrive >> size >> duration;
        guestInput[i] = Guest(arrive, size, duration, i);
    }
    while (M--) {
        int size, num;
        std::cin >> size >> num;
        available_table.insert({size, num});
    }

    for (int i = 0; i < N; i++) {
        Release(guestInput[i].arrive - 1);
        waiting_size.insert(guestInput[i]);
        waiting_time.insert(guestInput[i]);
        Release(guestInput[i].arrive);
        Assign(guestInput[i].arrive);
    }

    while (waiting_time.size()) Release(INT_MAX);

    for (int i = 0; i < N; i++) std::cout << ans[i] << '\n';

}

void Assign(int time) {
    while (waiting_time.size() && available_table.size()) {

        // search the targetGuest
        Guest targetGuest = *waiting_time.begin();

        // search the min table
        auto targetTable = available_table.lower_bound(targetGuest.size);

        // search the max-size table
        auto maxTable = available_table.rbegin();

        if (targetTable != available_table.end()) {

            // record the answer
            ans[targetGuest.id] = time;

            // update waiting_size
            waiting_size.erase(targetGuest);

            // update waiting_time
            waiting_time.erase(targetGuest);

            // updeate release_list
            release_list.insert(Table(targetTable->first, time + targetGuest.duration));

            // updeate available_table
            targetTable->second--;
            if (targetTable->second <= 0) available_table.erase(targetTable);

        }

        else if(maxTable->first >= waiting_size.rbegin()->size) {

            // search the targetGuest
            targetGuest = *waiting_size.upper_bound(Guest(-1, maxTable->first, 0, 0));

            // search the min table
            targetTable = available_table.lower_bound(targetGuest.size);

            // record the answer
            ans[targetGuest.id] = time;

            // update waiting_size
            waiting_size.erase(targetGuest);

            // update waiting_time
            waiting_time.erase(targetGuest);

            // updeate release_list
            release_list.insert(Table(targetTable->first, time + targetGuest.duration));

            // updeate available_table
            targetTable->second--;
            if (targetTable->second <= 0) available_table.erase(targetTable);

        }

        else break;
    }
}

void Release(int time) {
    while (release_list.size() && release_list.begin()->releaseTime <= time) {

        int sameTime = release_list.begin()->releaseTime;

        // release table for the same time
        while (release_list.begin()->releaseTime == sameTime) {

            int size = release_list.begin()->size;

            // updeate release_list
            release_list.erase(release_list.begin());

            // updeate available_table
            if (available_table.find(size) == available_table.end())
                available_table.insert({size, 1});
            else available_table[size]++;
        }

        // try assign after each release
        Assign(sameTime);
    }
}