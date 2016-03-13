package com.hatchinghealth.nopressure;

import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.AlertDialog;

/**
 * Created by Michelle on 3/12/2016.
 */
public class AddWearableDialogFragment extends DialogFragment {
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setTitle(R.string.wearables);

        builder.setPositiveButton(R.string.add_wearable, new DialogInterface.OnClickListener() {

            @Override
            public void onClick(DialogInterface dialog, int which) {
                // Add my wearable
            }
        });

        builder.setNegativeButton(R.string.cancel_wearable, null);

        return builder.create();
    }
}
