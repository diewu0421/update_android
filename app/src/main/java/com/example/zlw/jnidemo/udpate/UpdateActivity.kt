package com.example.zlw.jnidemo.udpate

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import com.example.zlw.jnidemo.R
import com.example.zlw.jnidemo.MainActivity
import com.example.zlw.jnidemo.udpate.utils.ApkUtils
import android.widget.Toast
import com.example.zlw.jnidemo.udpate.utils.BsPatch
import com.example.zlw.jnidemo.udpate.utils.DownloadUtils
import android.os.AsyncTask
import android.util.Log
import com.example.zlw.jnidemo.udpate.UpdateActivity.ApkUpdateTask
import com.example.zlw.jnidemo.udpate.utils.Constants


class UpdateActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_update)
//        ApkUpdateTask().execute()
    }

    internal inner class ApkUpdateTask : AsyncTask<Void, Void, Boolean>() {

        override fun doInBackground(vararg params: Void): Boolean? {
            try {
                //1.下载差分包
                Log.d("jason", "开始下载")
                val patchFile = DownloadUtils.download(Constants.URL_PATCH_DOWNLOAD)

                //获取当前应用的apk文件/data/app/app
                val oldfile = ApkUtils.getSourceApkPath(this@UpdateActivity, packageName)
                //2.合并得到最新版本的APK文件
                val newfile = Constants.NEW_APK_PATH
                val patchfile = patchFile.absolutePath
                BsPatch.patch(oldfile, newfile, patchfile)

                Log.e("jason", "oldfile:" + oldfile!!)
                Log.e("jason", "newfile:$newfile")
                Log.e("jason", "patchfile:$patchfile")
            } catch (e: Exception) {
                e.printStackTrace()
                return false
            }

            return true
        }

        override fun onPostExecute(result: Boolean?) {
            super.onPostExecute(result)
            //3.安装
            if (result!!) {
                Toast.makeText(this@UpdateActivity, "您正在进行无流量更新", Toast.LENGTH_SHORT).show()
                ApkUtils.installApk(this@UpdateActivity, Constants.NEW_APK_PATH)
            } else {
                Toast.makeText(this@UpdateActivity,"出现问题了",Toast.LENGTH_SHORT).show()
            }
        }

    }
}
