#include "../csapp.h"
//#include "json.h"
#include <stdio.h>
#include <regex.h>
regex_t regex;
int reti;
int main(void){
  char *buf, *p;
  int clientfd;
  char *host, buffer[100000], savebuffer[1000000], buffit[1000000], *port;
  char content[100000], arg1[MAXLINE], arg2[MAXLINE];
  int latitude= 0, longitude=0;
  //  int temp = 10;
  if ((buf = getenv("QUERY_STRING")) !=NULL){
    p = strchr(buf, '&');
    *p = '\0';
    strcpy(arg1, buf);
    strcpy(arg2, p+1);
  }
  sprintf(buffer, "GET /data/2.5/forecast?lat=%d&lon=%d&appid=d60399b985e81e4abde59059806944e7 HTTP/1.0\n\r\n\r",latitude, longitude);
 
  rio_t rio;

  host = "api.openweathermap.org";
  port = "80";

  clientfd = Open_clientfd(host, port);
  Rio_readinitb(&rio, clientfd);

  if (clientfd == -1){
    printf("ERROR: Connection couldnt be established");
  }
   Rio_writen(clientfd, buffer, MAXLINE); //should be strlen(buffer)
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);
   Rio_readlineb(&rio, savebuffer, MAXLINE);

   Rio_readlineb(&rio, savebuffer, MAXLINE);
   // printf("save buffer", "%s\n", savebuffer);
   //   Rio_readlineb(&rio, buffit, MAXLINE);   
   //sprintf(content, "%s%s", content, savebuffer);
   Close(clientfd);
                                                           
   //function getData(url) {                                                                                                                    
   //let request = new XMLHttpRequest()
      
   // request.open("GET", apiopenweathermap.org)                     
                                 
   // request.onload = function() {
                                    
   //   var weather = JSON.parse(request.weather.c)

   //   console.log(request)
   // console.log(request.responseText)
	  //   console.log(weather)
   //   console.log(weather.main.temp)
   // }   
   //  request.send()
   //}
   //var lon = %d
   //var lat = %d
   //getData("http://api.openweathermap.org/data/2.5/forecast?lat=" + lat + "&lon=" + lon)

   //  int reti = regcomp(&regex, ".*(temp\":).*,", 0);
   //  if (reti){
     //   fprint(stderr, "Could not ocmpile regex\n");
   // exit(1);
   // }
   //reti = regexc(&regex, savebuffer, 0, NULL, 0);
   //if (!reti){
   // puts(reti);
   // }
   //   public String getObject(String key, String JSON) {
   //Pattern p = Pattern.compile(String.format("\"%s\":\\s*(.*),", key));
   //Matcher matcher = pattern.matcher(JSON);
   //if(matcher.find())
   //  return matcher.group();
   //return null;
   //}
					     
     
   sprintf(content, "<html><body> <h1>The WeatherForcast</h1><form action='/cgi-bin/weatherTry?'>So which Lat you at: %d <br><input type='text' name='latitude'><br>Whats your Longitude Dude: %d <br><input type='text' name='longitude'><br><input type='submit' value='Submit'></form><h2>YOUR TEMPERATURE IS:</h2><h1>%s</h1><h2>Presented by: Aliza Pahmer, Chaya Green, and Michal Ladenheim</h2></body></html>", latitude, longitude,savebuffer);
   //sprintf(content,"%s%s%s",content, savebuffer,buffit);
   printf("Connection: close\r\n");
   printf("Content-length: %d\r\n", (int)strlen(content));
   printf("Content-type: text/html\r\n\r\n");
   printf("%s", content);
   fflush(stdout);

   exit(0);
}	
