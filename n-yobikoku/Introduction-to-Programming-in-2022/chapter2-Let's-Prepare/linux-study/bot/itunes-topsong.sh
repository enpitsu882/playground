#!/bin/bash
dirname="/linux-study/bot/itunes-topsong-rss"
mkdir -p $dirname
filename="${dirname}/hourly-topsong-`date +'%Y%m%d%H%M'`.xml"
echo "保存しました： $filename"
curl -s -o $filename -H "User-Argent: CrawlBot; enpitsu882@hotmail.co.jp" https://itunes.apple.com/jp/rss/topsongs/limit=10/xml