#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-21
# Author: Bryce

class Solution(object):
	def findSubstring(self, s, words):
		"""
		:type s: str
		:type words: List[str]
		:rtype: List[int]
		"""
		if not s or len(s)==0 or not words or len(words)==0:
			return []
		# 将每个单词以及出现的频率记录到字典中	
		words_map,res = dict(),[]
		for i in words:
			if i not in words_map:
				words_map[i] = 1
			else:
				words_map[i] += 1
		one_word_size = len(words[0])
		all_words_size = len(words)*one_word_size
		for i in range(len(s)-all_words_size+1):
			# 每次取 all_words_size长度的子串
			tmp_str,d = s[i:i+all_words_size],dict(words_map)
			# 将子串和临时字典进行比较
			for j in range(0,len(tmp_str),one_word_size):
				# 从子串tmp_str中取出one_word_size长度的子串，看是否出现在临时字典中
				# 如果是就将临时字典记录的频率-1，如果不在就跳出循环
				key = tmp_str[j:j+one_word_size]
				if key in d:
					d[key] -= 1
					if d[key]==0:
					    del d[key]
				else:
					break
			# 当内层循环遍历完后，如果临时字典为空则表示全部匹配上了
			# 记录数组的下标
			if not d:
				res.append(i)
		return res
