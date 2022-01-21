# java基础之BitSet

#### It depends on Java virtual machine.

> java中一个booliean有占用多少内存空间?
>
> 1. 1个bit位
> 2. 1个字节
> 3. 4个字节
>
> 其实都不对  因为**这取决于java虚拟机**
>
> 简单说:
>
> java规范中，没有明确指出boolean的大小。在《Java虚拟机规范》给出了4个字节，和boolean数组1个字节的定义，具体还要看虚拟机实现是否按照规范来，所以1个字节、4个字节都是有可能的。
>
> [点击了解详情](https://zhuanlan.zhihu.com/p/106203868)

进入正题:

## 引言

> 提问:判断一个正整数是否存在?
>
> 很快我们能想到的就是开一个boolean book数组规定true表示存在 false表示不存在
>
> 然后对于正整数i是否存在 只要判断book[i]是不是true就行了
>
> 但是如果是一个很大的数字比如i的值上亿了呢?
>
> 上面说到 It depends on Java virtual machine. 
>
> boolean 类型大小很不稳定
>
> 如果boolean算4个字节或者1个字节的时候 很明显那么就会导致内存的浪费

### 如何解决这个问题

> 我们只要不浪费空间不就完了,只要**每一个数字对应一个bit位**那么在一些情况下就可以节省32到8的空间
>
> 自JDK1.0以来 java.util包中提供一个类BitSet来解决这个问题

### BitSet基本用法

> ```java
> public BitSet()//空构造方法
> public BitSet(int nbits)//根据指定大小构造
> public void set(int bitIndex, boolean value)//设置第bitIndex位为value
> public boolean get(int bitIndex)//获取第bitIndex位的值
> ```

### 如何实现BitSet类(取自JDK11.0源码)

> JKD11.0当中是通过一个long数组的每一个bit位来标识数字
>
> 一个long占8个字节就可以表示64个数字
>
> 例如words[0]标识数字0~63
>
> words[1]表示数字64~127
>
> 即words[wordIndex]可以表示wordIndex &#42;64~(wordIndex+1) &#42;64-1
>
> ### 对于一个正整数x如何查询到words数组的第几位呢
>
> 我们先要找到x应用words数组的下标! 然后在找到对应的二进制位就行了
>
> ### 如何求words数组的下标
>
> 上面说道了words[wordIndex]可以表示wordIndex &#42;64~(wordIndex+1) &#42;64-1
>
> 那么就有
>
> **wordIndex &#42;64<=x<(wordIndex+1) &#42;64-1**
>
> **wordIndex &#42;64<=x<(wordIndex+1) &#42;64**
>
> **wordIndex<=x/64<(wordIndex+1)**
>
> wordIndex为下标
>
> 所以wordIndex=x/64    //(x/64)向下取整数
>
> 换成二进制就是wordIndex=x>>6;
>
> ### 如何求对应的二进制呢
>
> 只要x%64 那么就可以晓得x在words[wordIndex]的第几个bit位上了
>
> 于是有**words[wordIndex] & 1L << x)**来取这个bit位了

## 手写一个BitSet(应该有错误吧 没有测试过)

> ```java
> import java.util.Arrays;
> 
> public class BitSet {
>     private long[] words;
>     private static final int ADDRESS_BITS_PER_WORD = 6;
>     private static final int BITS_PER_WORD = 64;
>     private static final int BIT_INDEX_MASK = 63;
>     private transient boolean sizeIsSticky = false;
>     private transient int wordsInUse = 0;
> 
>     private void initWords(int nbits) {
>         this.words = new long[wordIndex(nbits - 1) + 1];//类似与数组 nbits如果是64的整数倍 那么他是不在范围内的是
>     }
> 
>     private static int wordIndex(int i) {
>         return i>>6;
>     }
> 
>     public BitSet() {
>         this.initWords(BITS_PER_WORD);
> 
>     }
>     public BitSet(int nbits){
>         this.initWords(nbits);
>     }
>     private void ensureCapacity(int wordsRequired) {
>         if (this.words.length < wordsRequired) {
>             int request = Math.max(2 * this.words.length, wordsRequired);
>             this.words = Arrays.copyOf(this.words, request);
>             this.sizeIsSticky = false;
> 
>         }
> 
>     }
> 
>     private void expandTo(int wordIndex) {
>         int wordsRequired = wordIndex + 1;
>         if (this.wordsInUse < wordsRequired) {
>             this.ensureCapacity(wordsRequired);
>             this.wordsInUse = wordsRequired;
>         }
> 
>     }
>     public void set(int bitIndex){
>         if(bitIndex<0){
>             throw new IndexOutOfBoundsException("不能搞负数");
>         }
>         int wordIndex = wordIndex(bitIndex);
>         this.expandTo(wordIndex);
>         this.words[wordIndex]|=1L<<bitIndex;
>     }
>     private void clear(int bitIndex) {
>         if(bitIndex<0){
>             throw new IndexOutOfBoundsException("不能搞负数");
>         }
>         int wordIndex = wordIndex(bitIndex);
>         this.expandTo(wordIndex);
>         this.words[wordIndex]&=~(1L<<bitIndex);//与上取反
>     }
>     public void set(int bitIndex,boolean value){
>         if(value){
>             this.set(bitIndex);
>         } else {
>             this.clear(bitIndex);
>         }
>     }
>     public boolean get(int bitIndex) {
>         if (bitIndex < 0) {
>             throw new IndexOutOfBoundsException("不能搞负数 " + bitIndex);
>         } else {
>             int wordIndex = wordIndex(bitIndex);
>             return wordIndex < this.wordsInUse && (this.words[wordIndex] & 1L << bitIndex) != 0L;//大于可以用范围直接不用判断了
>         }
>     }
> }
> ```