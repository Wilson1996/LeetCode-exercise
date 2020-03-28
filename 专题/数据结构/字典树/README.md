# 字典树/Trie树/前缀树



字典树又名前缀树，Trie树，是一种存储大量字符串的树形数据结构，相比于HashMap存储，在存储单词（和语种无关，任意语言都可以）的场景上，节省了大量的内存空间。

下图演示了一个保存了8个单词的字典树的结构，8个单词分别是："A", "to", "tea", "ted", "ten", "i", "in", "inn"。

![image.png](README.assets/22975162d4df780a94bfe38c79f72f9bca39e9083f08008b8a279d9f82a3e82f-image.png)


怎么理解这颗树呢？你从根节点走到叶子节点，尝试走一下所有的路径。你会发现，每条从根节点到叶子节点的路径都构成了单词（有的不需要走到叶子节点也是单词，比如 "i" 和 "in"）。trie树里的每个节点只需要保存当前的字符就可以了（当然你也可以额外记录别的信息，比如记录一下如果以当前节点结束是否构成单词）。

你注意到了吗？从根节点出发的路径，都是给定单词列表里某个/某些单词的前缀。反之，如果某个字符串没有出现在这棵树的路径上，那就肯定不是某个单词的前缀。上面说很明显这题是用字典树来做，原因就是：这类很明显是用字典树去做的题目，明显特征就是需要大量地判断某个字符串是否是给定单词列表中的前缀/后缀。 为什么要说后缀也可以呢？因为把单词倒着插入，就可以搜后缀了~

trie的节点的定义就很好给出来了（trie的根节点定义成一个空节点）：

	class TrieNode {
		char val;
		TrieNode[] children = new TrieNode[26];
	
		public TrieNode() {}
	
		public TrieNode(char val) {
	    	this.val = val;
		}
	}  

插入单词的操作如下：

	public void insert(String word) {
		TrieNode cur = root;
		for (int i = 0; i < word.length(); i++) {
	    	char c = word.charAt(i);
	    	if (cur.children[c - 'a'] == null) {
	        	cur.children[c - 'a'] = new TrieNode(c);
	    	}
	    	cur = cur.children[c - 'a'];
		}
	}
trie树除了刷题还出现在什么地方呢？

#### 搜索引擎

比如你在搜索引擎里输入”**甜**”，它会给你一系列以“甜”开头的搜索词供你选择。

#### 区块链
trie树的进阶版，Merkle Patricia Tree，他能够高效、安全地验证大型数据结构中的数据，我从别的地方摘抄了下摘要：

一种经过改良的、融合了默克尔树和前缀树两种树结构优点的数据结构，以太坊中，MPT是一个非常重要的数据结构，在以太坊中，帐户的交易信息、状态以及相应的状态变更，还有相关的交易信息等都使用MPT来进行管理，其是整个数据存储的重要一环。交易树，收据树，状态树都是采用的MPT结构。

IP路由，倒排索引
这个感兴趣的可以去了解下，我也不太了解，这是听说过可以🤣😂

分词
常见的分词库，或多或少会用到字典树，或者其它类似的存储字符串的树形数据结构（比如"双数组trie树"）。原因就是因为它能提供良好的前缀查询（一些分词算法需要大量调用该方法）。

python有一个很著名的分词库叫做jieba，里面就用到了字典树（虽说由于jieba源码里字典树实现得不够优雅，后来被替代了🤣）。这个库有java版本叫做jieba-analysis，但是已经很久不更新了，而且分词结果和python版本的不一致！

作者：sweetiee
链接：https://leetcode-cn.com/problems/short-encoding-of-words/solution/99-java-trie-tu-xie-gong-lue-bao-jiao-bao-hui-by-s/