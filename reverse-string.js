var myStr = "Reverse, this is a string,      hello\n";
var reversedStr = "";
var lastIdx = myStr.length - 2;
for(var i = myStr.length - 1; i >= 0; i--){
	if(myStr[i] !== "\n"){
		if(myStr[i] === " "){
			reversedStr += myStr.substring(i + 1, lastIdx + 1);
			if(myStr[i - 1] == ","){
				reversedStr += myStr[i - 1];
				lastIdx = i - 2;
			}else{
				lastIdx = i - 1;
			}
			reversedStr += myStr[i];
		}else if(i === 0){
			reversedStr += myStr.substring(i, lastIdx + 1);
		}
	}
}
console.log(reversedStr);

