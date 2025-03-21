// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
// 2115. Find All Possible Recipes from Given Supplies


// 1 - form a dependency graph (directed, unweighted) i.e. adjacency list for each element in recipes
// 2 - store all supplies in a set to check if we have it or not in O(1)
// 3 - if the supply is not present for any recipe we can't make it. 
// 4 - store a bool value with each vertex/recipe which indicates whether we can make it or not (default : 1)
// 5 - if we can't make it, update to 0 and return false from there only 
// 6 - if the complete dfs returns true, we can make it, so push the recipe in result vector
// 7 - return result

class Solution {
    private:
        unordered_map<string, vector<string>> recipeGraph;
        unordered_set<string> suppliesSet;
        unordered_map<string, int> dp;
    
        bool canMake(const string &item) {
            if (suppliesSet.count(item)) return true;
            if (recipeGraph.find(item) == recipeGraph.end()) return false;
            if (dp.count(item)) return dp[item] == 2;
            dp[item] = 1;
            for (const string &ing : recipeGraph[item]) {
                if (!canMake(ing)) {
                    dp[item] = 3;
                    return false;
                }
            }
            dp[item] = 2;
            return true;
        }
        
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            for (int i = 0; i < recipes.size(); i++) recipeGraph[recipes[i]] = ingredients[i];
            suppliesSet = unordered_set<string>(supplies.begin(), supplies.end());
            
            vector<string> result;
            for (const string &recipe : recipes) {
                if (canMake(recipe))
                    result.push_back(recipe);
            }
            return result;
        }
    };
    