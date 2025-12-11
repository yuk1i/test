#include <iostream>

class Transaction {
public:
    int id;
    double amount;
};
Transaction* createTxn();

// 【单过程分析目标】
// 这是一个独立的函数，没有 this 指针
void processTransaction(int flowControl) {
    
    // [L1] 初始定义
    // 假设 createTxn() 可能返回 nullptr，也可能返回有效对象
    // 初始状态 Fact: { txn: MaybeNull }
    Transaction* txn = createTxn();
    
    // [L2] 第一次检查 (Constraint)
    if (txn != nullptr) {
        // [L3] True 分支
        // 这里的约束是: txn != nullptr
        // 当前 Fact: { txn: NonNull }
        
        // 【绝对安全】分析器确定这里绝不会崩
        txn->amount = 10; 
        std::cout << "Transaction Validated." << std::endl;
    } 
    // [L4] 分支结束，汇合
    // 来自 True: NonNull
    // 来自 False (隐含): MaybeNull (因为如果原来是Null，就没进if，还是Null)
    // Merge 结果: { txn: MaybeNull }


    // ---------------------------------------------------------
    // 场景 2: 绝对不安全 (Definitely Unsafe / Must-Fail)
    // ---------------------------------------------------------

    // [L5] 人为制造的错误逻辑
    if (flowControl == -1) {
        // [L6] 强更新 (Strong Update)
        // 我们显式地把指针“杀”死了
        txn = nullptr; 
        // 当前 Fact: { txn: Null }

        // [L7] 愚蠢的操作
        // 这里的约束是 flowControl == -1，且 txn 肯定是 nullptr
        // 【绝对不安全】分析器在这里应该报 ERROR 而不是 Warning
        std::cout << "Bad ID: " << txn->id << std::endl; // CRASH!
        
        return; // 结束这条路径
    }


    // ---------------------------------------------------------
    // 场景 3: 潜在风险 (Maybe Unsafe)
    // ---------------------------------------------------------
    
    // [L8] 这里的代码处于主干道
    // 此时的 Fact 是什么？
    // 1. 如果走了 L2 的 True 分支，它是 NonNull
    // 2. 如果走了 L2 的 False 分支，它是 Null
    // 3. L5 的路径已经 return 了，不考虑
    // 结论 Fact: { txn: MaybeNull }

    if (flowControl > 0) {
        // [L9] 无保护访问
        // 因为状态是 MaybeNull (既可能是空，也可能非空)
        // 【潜在风险】分析器报 Warning
        std::cout << "Processing ID: " << txn->id << std::endl; 
    }
}