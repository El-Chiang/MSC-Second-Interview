#coding=utf-8

from urllib import request
import codecs
import time
import re
import os

n = os.linesep

req = request.Request('https://weibo.cn/pub/topmblog')
req.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36 Edge/15.15063')

with request.urlopen(req) as f:
	str = f.read().decode('utf-8')
	
	namePattern = re.compile(r'<a class="nk".*?>(.*?)</a>')
	articlePattern = re.compile(r'<span class="ctt">:(.*?)</span>')
	
	listName = namePattern.findall(str)
	listArticle = articlePattern.findall(str)
	
	time = time.strftime('%Y_%m_%d_%H_%M_%S', time.localtime(time.time()))
	timestr = '现在是' + time + '，目前微博热门前10按先后顺序如下：' + n + n
	
	with codecs.open(time + '.log', 'w','utf-8') as writer:
		print(timestr)
		writer.write(timestr)
		for i in range(0,9):
			listArticle[i] = re.sub('<a.*?>',' ',listArticle[i])
			listArticle[i] = re.sub('</a>',' ',listArticle[i])
			listArticle[i] = re.sub('<br/>',' ',listArticle[i])
			listArticle[i] = re.sub('&lt;','<',listArticle[i])
			listArticle[i] = re.sub('&gt;','>',listArticle[i])
			listArticle[i] = re.sub('&nbsp;','',listArticle[i])
			result = '博主：['+listName[i]  + '] ' + n + '内容：[' + listArticle[i] + ']' + n + n;
			print(result)
			writer.write(result)
print ('==============================以上内容已写入日志==============================\n')
os.system("pause")