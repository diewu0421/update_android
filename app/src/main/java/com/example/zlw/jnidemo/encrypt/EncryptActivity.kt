package com.example.zlw.jnidemo.encrypt

import android.Manifest
import android.content.Context
import android.content.pm.PackageManager
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.support.v4.app.ActivityCompat
import android.support.v4.content.ContextCompat
import android.support.v4.content.PermissionChecker
import android.util.Log
import android.widget.Toast
import com.example.zlw.jnidemo.R
import kotlinx.android.synthetic.main.activity_encrypt.*
import java.io.File
import java.security.Permission

class EncryptActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_encrypt)
        encrypt.setOnClickListener {
            val normal_path = "${Environment.getExternalStorageDirectory()}${File.separator}liuyan.png"
            Log.e(TAG, "normal = $normal_path")
            val crypt_path = "${Environment.getExternalStorageDirectory()}${File.separator}liuyan_crypt.png"
            Log.e(TAG, "normal = $crypt_path")
            Cryptor.crypt(normal_path, crypt_path)
            Toast.makeText(this@EncryptActivity, "加密成功", Toast.LENGTH_SHORT).show()
        }

        decrypt.setOnClickListener {
            val crypt_path = "${Environment.getExternalStorageDirectory()}${File.separator}liuyan_decrypt.png"
            Log.e(TAG, "normal = $crypt_path")
            val normal_path = "${Environment.getExternalStorageDirectory()}${File.separator}liuyan_crypt.png"
            Log.e(TAG, "normal = $normal_path")
            Cryptor.decrypt(normal_path, crypt_path)
            Toast.makeText(this@EncryptActivity, "解密成功", Toast.LENGTH_SHORT).show()
        }
        val hasWreteExternalStore = PermissionChecker.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE)
        if (hasWreteExternalStore != PackageManager.PERMISSION_GRANTED) {
            encrypt.isEnabled = false
            decrypt.isEnabled = false
            ActivityCompat.requestPermissions(this,
                    arrayOf(Manifest.permission.WRITE_EXTERNAL_STORAGE), 100)
        } else {
            encrypt.isEnabled = true
            decrypt.isEnabled = true
        }

    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == 100) {
            if (grantResults.isNotEmpty()) {
                encrypt.isEnabled = true
                decrypt.isEnabled = true
            }
        }
    }

    companion object {
        val TAG = "EncryptActivity"
    }
}
