//1、拒绝采样


//2、蓄水池采样
/*
算法思路大致如下：
1) 如果接收的数据量小于m，则依次放入蓄水池。
2) 当接收到第i个数据时，i >= m，在[0, i]范围内取以随机数d，若d的落在[0, m-1]范围内，
   则用接收到的第i个数据替换蓄水池中的第d个数据。
3) 重复步骤2。
算法的精妙之处在于：当处理完所有的数据时，蓄水池中的每个数据都是以m/N的概率获得的。
*/
int[] reservoir = new int[m];
// init
for (int i = 0; i < reservoir.length; i++) {
    reservoir[i] = dataStream[i];
}

for (int i = m; i < dataStream.length; i++) {
    // 随机获得一个[0, i]内的随机整数
    int d = rand.nextInt(i + 1);
    // 如果随机整数落在[0, m-1]范围内，则替换蓄水池中的元素
    if (d < m) {
        reservoir[d] = dataStream[i];
    }
}


//3、随机洗牌算法