export VIPER_HOME="/home/ansuman/VParsER"
export VIPER_REG_HOME="/home/ansuman/VParsER/regression"
cd $VIPER_REG_HOME
rm -rf Report; mkdir Report

if [ "$#" -ne 1 ]
then
	    echo "Correct Run command :"
	    echo "./runRegression.sh -all "
	    echo "./runRegression.sh directoryName"
	    exit
fi

if [ $1 == "-all" ] 
then
   ls */*.sv|cut -d "/" -f1>dir_list   # get all directory list from regression directory
else 
   echo $1>dir_list   # get specific directory from regression directory
fi


cat dir_list|while read dir1   #Enter every regression directory
do
   cd $dir1                 
   ls *.sv >file_list    #list all .sv files 
   cat file_list | while read file1
   do
      echo $file1
      fileName=`echo $file1|cut -d "." -f1`
      runExt="-Run.txt"
      goldExt="-Gold.txt"
      runFileName=$fileName$runExt                  #create file name for *-Run.txt
      goldFileName=$fileName$goldExt                  #create file name for *-Gold.txt
      $VIPER_HOME/vper  $file1 > $runFileName           #run vper command
      cp $runFileName $goldFileName           #create gold file
	  #diff $runFileName $goldFileName
      rm $runFileName
   done
   rm file_list
cd $VIPER_REG_HOME
done

rm dir_list
