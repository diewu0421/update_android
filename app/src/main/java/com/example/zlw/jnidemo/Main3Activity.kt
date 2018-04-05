package com.example.zlw.jnidemo

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.util.Log
import android.widget.Toast
import java.util.*

/**
 * Main3Activity
 *
 * @author zlw
 * @date 2018/3/29
 */

class Main3Activity : AppCompatActivity() {

    external fun getStringFromC():String
    private var mMember1:String? = null


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        mMember1 = "nihao"
        Log.e(TAG, "修改之前的值为: $mMember1")

//        Toast.makeText(this, getStringFromC(), Toast.LENGTH_SHORT).show()
        getStringFromC()
//        mMember1 = "xiugaizhihou "

        Log.e(TAG, "修改之后的值为: $mMember1")

        Log.e(TAG,"修改之前的静态属性count的值为:$count")
        accessStaticField()
        Log.e(TAG,"修改之后的静态属性count的值为:$count")
        Log.e(TAG, "获取的随机数为:${accessGetRandom()}")
//        Log.e(TAG,"获取的UUID为: ${accessGetUUID()}")

        val p = Person("zlw")
        val uuid =  p.accessGetUUID()
        Log.e(TAG, "UUID= ${uuid}")


        val p2 = Person1("zlw")
        val uuid2 = p2.accessGetUUID2()
        Log.e(TAG, "UUID2 = $uuid2")


        /*****************************************************************************************************************************/
//        Toast.makeText(this,p.testStaticMethod(),Toast.LENGTH_SHORT).show()
        val date = accessConstructor()
        Log.e(TAG, date.toString() + "${date.time}")

//        man.sayHi()
        accessNonvirtualMethod()
        //中文问题
        Log.e(TAG,chineseChars("宋哲"))
       /*****************************************************************************************************************************/
       val intArray = intArrayOf(9,100,10,37,5,10)
        giveArray(intArray)
        intArray.forEach {
            Log.e(TAG, "$it")

        }

        /*****************************************************************************************************************************/
        Log.e(TAG, "----------------------------------------------")
        val returnArray = getArray(5)
        returnArray.forEach {
            Log.e(TAG, "$it")
        }

        /*****************************************************************************************************************************/
        localRef()
        /*****************************************************************************************************************************/
        //全局引用
        createGlobalRef()
        Log.e(TAG, "获取的全局引用为:${getGlobalRef()}")
        deleteGlobalRef()
        //会报错，因为全局引用已经被释放了
        //Log.e(TAG, "获取的释放之后的全局引用:${getGlobalRef()}")

        try {
            handleException()
        } catch (e: Exception) {
           Log.e(TAG,"异常了 ${e.message}")
        }

        Log.e(TAG,"异常之后")
        /*****************************************************************************************************************************/
        //测试缓存
        cache()
        /*****************************************************************************************************************************/


    }

    //这是已经实现了的方法，c调用它
    fun genarateRandomInt(max:Int): Int {
        Log.e(TAG,"accessGetRandom()方法执行L ")
        return Random().nextInt(max)
    }


    external fun getMenberFromC():String
    external fun accessStaticField()
    external fun accessGetRandom():Int
    external fun accessGetUUID():String
    external fun accessConstructor():Date
    external fun accessNonvirtualMethod()
    external fun chineseChars(`in`:String):String
    external fun giveArray(arr:IntArray)
    external fun getArray(len:Int):IntArray
    external fun localRef()
    external fun createGlobalRef()
    external fun getGlobalRef() :String
    external fun deleteGlobalRef()
    external fun handleException()
    external fun cache()


    val man:Human = Man()
    val key = "zlw"
    companion object {

        val TAG = this::class.java.simpleName
        private var count = 9
        private external fun initIDs()
        init {
            System.loadLibrary("native-lib-c")
//            initIDs()
            Log.e(TAG, Person.testStaticMethod())
        }

        fun getUUID() :String {
            return UUID.randomUUID().toString()
        }
    }
}
