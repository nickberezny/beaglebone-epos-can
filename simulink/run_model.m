bbblue = beagleboneblue;
isModelRunning(bbblue,'controller')
if(isModelRunning(bbblue,'controller'))
    
    stopModel(bbblue,'controller');

end
runModel(bbblue,'controller');

