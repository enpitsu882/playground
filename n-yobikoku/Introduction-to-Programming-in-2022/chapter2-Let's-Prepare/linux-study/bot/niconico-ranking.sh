#!/bin/bash
dirname="/linux-study/bot/niconico-ranking-rss"
mkdir -p $dirname
filename="${dirname}/hourly-ranking-`date +'%Y%m%d%H%M'`.xml"
echo "保存しました： $filename"
curl -s -o $filename -H "User-Argent: CrawlBot; enpitsu882@hotmail.co.jp" https://www.nicovideo.jp/ranking/genre/all?rss=2.0&lang=ja-jp