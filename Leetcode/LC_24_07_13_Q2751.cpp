// Link - https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2024-07-13
// Robot Collisions


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
    vector<int> result(n, -1);

    // Create a vector of robots with their positions, health, direction, and original index.
    vector<tuple<int, int, char, int>> robots;
    for (int i = 0; i < n; ++i) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    // Sort robots based on their positions.
    sort(robots.begin(), robots.end());

    // Stack to keep track of robots moving to the right.
    stack<tuple<int, int, int>> rightMoving;

    // Process each robot in order.
    for (auto& [pos, health, dir, idx] : robots) {
        if (dir == 'R') {
            rightMoving.push({health, pos, idx});
        } else { // dir == 'L'
            while (!rightMoving.empty() && get<0>(rightMoving.top()) < health) {
                health--;
                rightMoving.pop();
            }
            if (!rightMoving.empty()) {
                if (get<0>(rightMoving.top()) > health) {
                    auto& topHealth = get<0>(rightMoving.top());
                    topHealth--;
                } else if (get<0>(rightMoving.top()) == health) {
                    rightMoving.pop();
                }
            } else {
                result[idx] = health;
            }
        }
    }

    // Remaining robots in the stack have no collisions.
    while (!rightMoving.empty()) {
        result[get<2>(rightMoving.top())] = get<0>(rightMoving.top());
        rightMoving.pop();
    }

    // Filter out the robots that have been removed.
    vector<int> survivors;
    for (const int health : result) {
        if (health != -1) {
            survivors.push_back(health);
        }
    }

    return survivors;
    }
};