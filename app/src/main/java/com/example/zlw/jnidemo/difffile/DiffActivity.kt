package com.example.zlw.jnidemo.difffile

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.widget.Toast
import com.example.zlw.jnidemo.R
import kotlinx.android.synthetic.main.activity_diff.*
import java.io.File
import java.nio.file.Paths
import kotlin.concurrent.thread

class DiffActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_diff)
        val path = SDK_PATH + PATH_SEP + "movie.mp4"
        val pattern = SDK_PATH + PATH_SEP + "movie_%d.mp4"
        diff.setOnClickListener {
            thread {
                DiffUtil.diff(path,pattern,3)
                runOnUiThread {
                    Toast.makeText(this@DiffActivity,"拆分文件成功!",Toast.LENGTH_SHORT).show()
                }
            }
        }
        patch.setOnClickListener {
//            DiffUtil.patch()
            thread {
                DiffUtil.patch(SDK_PATH + PATH_SEP + "movie_patch.mp4", pattern, 3)
                runOnUiThread {
                    Toast.makeText(this@DiffActivity,"合并文件成功!",Toast.LENGTH_SHORT).show()
                }
            }
        }
    }


    companion object {
        val TAG = this::class.java.simpleName
        val SDK_PATH = Environment.getExternalStorageDirectory().absolutePath
        val PATH_SEP = File.separator
    }
}
