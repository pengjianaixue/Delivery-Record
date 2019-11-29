# -*- mode: python -*-

block_cipher = None


a = Analysis(['Delivery_note_record.py'],
             pathex=['C:\\Users\\eijpnae\\Documents\\Visual Studio 2015\\Projects\\Delivery Record\\Win32\\Debug\\Delivery_Record_WIKI_Proxy_Server'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          [],
          name='Delivery_note_record',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          runtime_tmpdir=None,
          console=True )
