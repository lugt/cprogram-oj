CURDIRD=$(pwd)
APP_NAME=$1
RUN_CMD="cat $APP_NAME.in | ./$APP_NAME > ./$APP_NAME.log"

if [ -z $APP_NAME ]; then
    echo "Usage : $0 CLASS_NAME"
    exit 3
fi


echo "-------------------------------------"
echo " Running in $CURDIRD"
echo " Input : "
echo "-------------------------------------"
if [ ! -f $APP_NAME.in ]; then
    echo "Cannot locate $APP_NAME.in, abort"
    exit 3
fi
cat $APP_NAME.in
echo
echo " "
echo " "
echo "-------------------------------------"
echo " Output: "
echo "-------------------------------------"
if [ ! -f $APP_NAME.out ]; then
    echo "Cannot locate $APP_NAME.out, abort"
    exit 3
fi
cat $APP_NAME.out
echo " "
echo " "
echo "-------------------------------------"
echo " Running make "
echo "-------------------------------------"
make -j 3
echo " "
echo " "
echo "-------------------------------------"
echo " Running $RUN_CMD "
echo "-------------------------------------"
cat ./$APP_NAME.in | ./$APP_NAME > ./$APP_NAME.log
echo " "
echo " "

echo " "
echo " "
echo "-------------------------------------"
echo " Result "
echo "-------------------------------------"
cat $APP_NAME.log
diff $APP_NAME.log $APP_NAME.out
if [ $? -eq 0 ]; then
    echo "***************"
    echo "Test Success !"
    echo "***************"
else
    echo "***************"
    echo "Test Failed  !"
    echo "***************"
fi
