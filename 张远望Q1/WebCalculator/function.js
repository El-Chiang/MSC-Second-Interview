var lastkey="";
var re1=/^[\*|\/|\%].+/; 
var re2=/.+[\*|\/|\+|\-|\%]$/;
var re3=/(\+|\-|\*|\/|\%)/;                                
var results="";
var calresults="";
    function calculator(){
		if(lastkey.match(re3)&&event.srcElement.innerText.match(re3)){//防止手贱连续输入两个运算符
            return;
        }
		if (event.srcElement.innerText=="=") {//等号不会被输入到display框中             
            return;
	    }
		if (event.srcElement.innerText=="sin"){//sin不会被输入到display框中
            return;
	    }
        if (event.srcElement.innerText=="c") {//C键初始化             
            results="";
            display.innerText="";
            return;
        }	
        if (event.srcElement.id=="display") {//点击display框时不会复制内容              
            return;
        }		
        results+=event.srcElement.innerText;//实现连续输入
        display.innerText=results;  
        lastkey=event.srcElement.innerText		
    }
	function resultscalculate(){//判断第一位和最后一位是否是*或/
	    if (results.match(re1)||results.match(re2)) {
           display.innerText="Error!!";
           results="";
           return;
        }                                                    
		calresults=eval(results);//实现四则运算和取模运算
        display.innerText=calresults;
    }
	function sine(){//实现正弦运算
	    calresults=Math.sin(results*Math.PI/180)
		display.innerText=calresults;
	}
	