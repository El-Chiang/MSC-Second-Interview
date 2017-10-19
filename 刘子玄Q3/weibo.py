# -*- coding: UTF-8 -*-
import requests
import sys
import json
from bs4 import BeautifulSoup
import re
import time
import random
imgList=[]
def nothing():
	i="liuzixuan"
def getNick(content):
	nickList = content.findAll("a",attrs={"class": "nk"})
	nick = []
	for nicks in nickList:
		nick.append(nicks.getText())
	return nick
def getContent(content):
	contentList = content.findAll("span",attrs={"class": "ctt"})
	weiboContent = []
	imgSrc = []
	for contents in contentList:
		weiboContent.append(contents.getText()[1:])
		imgMark = contents.parent.parent.findAll("img",attrs={"class": "ib"})
		for img in imgMark:
			imgSrc.append(img.get("src"))
		if not imgMark:
			imgSrc.append(None)
	imgDownloader(imgSrc)
	return weiboContent
def imgDownloader(img):
	print("下载附带图片...")
	global imgList
	for singleImg in img:
		if not singleImg:
			imgList.append("没有图片")
		else:
			download = requests.get(singleImg, stream=True)
			fileName = str(int(time.time()+random.uniform(1,100)))
			with open('/img/'+fileName+'.jpg', 'wb') as f:
				for chunk in download:
					f.write(chunk)
			imgList.append('保存至：/img/'+fileName+'.jpg')
def getTogether(nicks,contents):
	global imgList
	weiboInfo=[]
	counter = 0
	for nick in nicks:
		single_info={}
		single_info["nick"] = nick
		single_info["content"] = contents[counter]
		single_info["img"] = imgList[counter]
		counter = counter+1
		weiboInfo.append(single_info)
	for single in weiboInfo:
		print("【昵称:"+single["nick"]+",内容:"+single["content"]+"],图片:"+single["img"]+"】")
if __name__ == '__main__':
	print("请求热门微博页面...")
	r = requests.get('https://weibo.cn/pub/topmblog')
	soup = BeautifulSoup(r.text, "html.parser")
	c = getContent(soup)
	getTogether(getNick(soup),c)