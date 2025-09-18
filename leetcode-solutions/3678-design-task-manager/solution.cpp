class TaskManager {
public:
    set<vector<int>> manager;
    unordered_map<int, vector<int>> taskMap;

    TaskManager(vector<vector<int>>& tasks) {
        manager.clear();
        taskMap.clear();
        for (vector<int>& i : tasks) {
            int userId = i[0];
            int taskId = i[1];
            int priority = i[2];
            manager.insert({priority, taskId, userId});
            taskMap[taskId] = {priority, taskId, userId};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        vector<int> task = {priority, taskId, userId};
        manager.insert(task);
        taskMap[taskId] = task;
    }
    
    void edit(int taskId, int newPriority) {
        vector<int> prevTask = taskMap[taskId];
        vector<int> newTask = {newPriority, taskId, prevTask[2]};
        manager.erase(prevTask);
        manager.insert(newTask);
        taskMap[taskId] = newTask;
    }
    
    void rmv(int taskId) {
        vector<int> task = taskMap[taskId];
        manager.erase(task);
        taskMap.erase(taskId);
    }
    
    int execTop() {
        auto ptr = manager.rbegin();
        if (ptr == manager.rend()) return -1;
        vector<int> task = *ptr;
        int userId = task[2];
        int taskId = task[1];
        rmv(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
