/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#include <semaphore.h>
class DiningPhilosophers {
public:
    DiningPhilosophers() {
        sem_init(&people, 0, 4);

        fork = vector<sem_t>(5);
        for (int i = 0; i < 5; i++) {
            sem_init(&fork[i], 0, 1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        sem_wait(&people);
        sem_wait(&fork[philosopher % 5]);
        sem_wait(&fork[(philosopher + 1) % 5]);

        pickLeftFork();
        pickRightFork();

        eat();

        putRightFork();
        putLeftFork();

        sem_post(&fork[(philosopher + 1) % 5]);
        sem_post(&fork[philosopher % 5]);
        sem_post(&people);
    }

    sem_t people;
    vector<sem_t> fork;
};
// @lc code=end

